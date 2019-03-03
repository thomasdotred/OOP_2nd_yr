#ifndef MRI_SCAN_H_INCLUDED
#define MRI_SCAN_H_INCLUDED
#include <fstream> // for writing to file
#include <string> // for filenames

using namespace std;

class MRI_Scanner // MRI class definition
{
    public:
        MRI_Scanner(){};
        void WriteData(float Tip_Loc[3], string outfilename) // function for writing latest tip location to a file
        {
            ofstream out_data; // create output stream variable
            out_data.open(outfilename.c_str(), std::ofstream::app); // open or create file outfilename and append out_data
            out_data << Tip_Loc[0] << " " << Tip_Loc[1] << " " << Tip_Loc[2] << endl; // output tip coordinates
            out_data.close(); // close file
        };
};
#endif // MRI_SCAN_H_INCLUDED
