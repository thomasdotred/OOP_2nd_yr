#include <iostream>
#include <fstream > // for reading from file
#include "Simulator.h"
#include <string> // for filenames and catheter types

using namespace std;

// ReadData has two string arguments - one for input filename and one for output
int Simulator :: ReadData(string infilename, string outfilename)
{
    ifstream in_data; // create input stream variable
    in_data.open(infilename.c_str()); // open file infilename
    if (!in_data ) // error check for input file
    {
        cerr << " Error 1: Cannot open .txt file." << endl ; // return error 1 if invalid file
        return 1;
    }

    // Initialize variables
    char _Cath_Type; // catheter type
    int _Nsamples; // number of samples
    float Avg[] = {0,0,0}; // array for calculating average coordinates
    in_data >> _Cath_Type; // read in catheter type indicator
    in_data >> _Nsamples; // read in number of samples
    float temp_coord[_Nsamples][6]; // 2D array for temporal coordinates
    float Current_Tip_Loc[3]; // array for for current tip locations
    int _L = 0; // number of likely tip locations
    int _U = 0; // number of unlikely tip locations

    // Use catheter indicator to instantiate catheter
    if (_Cath_Type == 'a')
    {
        _cath = new Ablation; // instantiate catheter as ablation
    }
    else if (_Cath_Type == 'd')
    {
        _cath = new Diagnostic; // instantiate catheter as diagnostic
    }
    else
    {
        cerr << " ERROR 2: Unrecognised catheter type." << endl; // return error 2 if catheter indicator unrecognized
        return 2;
    }
    // Use for loop to read in temporal samples
    for (int i = 0; i < _Nsamples; i++) // rows of samples
    {
        for (int j = 0; j < 6; j++) // columns of samples. Format {x_p y_p z_p x_d y_d z_d}, where p is proximal, d is distal
        {
            in_data >> temp_coord[i][j]; // read sample values into array
        }
        _cath -> calc_tip_loc(temp_coord[i], i); // pass sample row into catheter

        for (int j = 0; j < 3; j++)
        {
            Current_Tip_Loc[j] = _cath->Get_current_tip_loc(j); // retrieve current tip location from catheter
            if (_cath->Get_current_tip_loc(3) == 1) // check if tip location is likely
            {
                Avg[j] = Avg[j] + Current_Tip_Loc[j]; // add current tip location to running sum if likely
            }
        }

        // Check if current tip location is likely or unlikely, add to total as appropriate
        if (_cath->Get_current_tip_loc(3) == 1)
            _L = _L + 1; // increase likely
        else if (_cath->Get_current_tip_loc(3) == 0)
            _U = _U + 1; // increase unlikely
        _MRI->WriteData(Current_Tip_Loc, outfilename); // pass current tip location and filename to MRI for writing to file
    }

    // Use for loop to convert running sum of realistic tip locations to an average
    for (int i = 0; i < 3; i++)
    {
       Avg[i] = Avg[i]/_L; // divide sum of likely tip coordinates by number likely locations
    }
    in_data.close(); // close file

    DisplayResults(_cath->Get_type(), _cath->Get_thresh(), Avg, _L, _U); // Display results
    return 0;
}

// DisplayResults takes arguments for catheter type, threshold for type, average location,
// and number of likely and unlikely locations, and then prints a summary.
void Simulator :: DisplayResults(string Cathtype, int Cath_Thresh, float Avg[3], float _L, float _U)
{
    float Perc_Like, Perc_Unlike; // initialize percentage of likely/unlikely locations
    Perc_Like = ((_L)/(_L + _U))*100; // calculate percentage of likely locations
    Perc_Unlike = 100 - Perc_Like; // calculate percentage of unlikely locations

    // Print summary:
    cout << Cathtype << " catheter (distance threshold: " << Cath_Thresh << "mm)" << endl;
    cout << "Average location (x/y/z): " << Avg[0] << "/" << Avg[1] << "/" << Avg[2] << "mm" << endl;
    cout << "Percentage of 'realistic' locations: " << Perc_Like << "%" << endl;
    cout << "Percentage of 'unlikely'locations: " << Perc_Unlike << "%" << endl;
}
