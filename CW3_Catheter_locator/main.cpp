#include <iostream>
#include "Simulator.h"
#include <string> // for input and output file names

using namespace std;

int main()
{
    string indata, Tiploc;
    indata = "inputSample2.txt"; // input filename
    Tiploc = "TipLocations.txt"; // input filename
    Simulator cathloc; // instantiate simulator Sim
    cathloc.ReadData(indata, Tiploc); // Run ReadData function of Sim
    return 0;
}
