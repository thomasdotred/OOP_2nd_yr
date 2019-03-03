#ifndef CATHETER_H_INCLUDED
#define CATHETER_H_INCLUDED
#include <string> // for catheter types

using namespace std;

class Catheter // catheter class definition
{
    protected:
        // Define data members
        int _N;
        float _delta_loc; // difference between two locations
        float last_tip_loc[3]; // previous locations
        float current_tip_loc[4]; //current location likelihood indicator
        int _thresh; // threshold
        string _type; // catheter type

    public:
        Catheter() {};
        //int GetN() const { return _N; }; // returns number of samples
        float Get_current_tip_loc(int j) { return current_tip_loc[j]; }; // returns jth element of current tip location
        int Get_thresh() { return _thresh; }; // return catheter threshold
        string Get_type() {return _type; }; // return catheter type
        void calc_tip_loc(float Coil_Locs[], int i); // calculate tip location from coil locations
        float calc_delta(); // compute distance between current and previous tip locations
        virtual bool realtest(float _delta_loc) = 0; // determine likelihood of tip location

};
class Ablation : public Catheter
{
    public:
        Ablation()
        {
            _type = "Ablation"; // set catheter type as string
            _thresh = 1.0; // set catheter threshold for ablation
        };
         bool realtest(float _delta_loc) // determine likelihood of tip location for ablation catheter
        { if (_delta_loc < 1.0)
            return true;
          else
            return false;
        };
};
class Diagnostic : public Catheter
{
    public:
        Diagnostic()
        {
            _type = "Diagnostic"; // set catheter type as string
            _thresh = 2.0; // set catheter threshold for ablation
        };
        bool realtest(float _delta_loc) // determine likelihood of tip location for ablation catheter
        {
            if (_delta_loc < 2.0)
                return true;
            else
                return false;
        };
};
#endif // CATHETER_H_INCLUDED
