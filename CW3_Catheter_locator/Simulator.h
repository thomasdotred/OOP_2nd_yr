#ifndef SIMULATOR_H_INCLUDED
#define SIMULATOR_H_INCLUDED
#include <string> // for filenames
#include "Catheter.h"
#include "MRI_Scan.h"

using namespace std;

class Simulator // Simulator class definition
{
    public:
        Simulator() {};
        ~Simulator() { delete _cath; delete _MRI; } // delete MRI and catheter when simulator goes out of scope
        int ReadData(string infilename, string outfilename); // Read data prototype with input and output filenames
        void DisplayResults(string type, int thresh, float Avg[3], float _L, float _U); // DisplayResults prototype
    protected:
        Catheter * _cath = NULL; // allocate memory space for Catheter object
        MRI_Scanner *_MRI = NULL; //allocate memory space for MRI_Scanner object
};
#endif // SIMULATOR_H_INCLUDED
