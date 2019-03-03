#include <iostream>
#include "Catheter.h"
#include <math.h>

using namespace std;

// Member functions for the catheter class

// Function for computing current location of tip from sample coil locations
void Catheter :: calc_tip_loc(float Coil_Loc[], int i)
{
    // Calculate tip locations from coil locations:
    current_tip_loc[0] = (Coil_Loc[0]*2) - Coil_Loc[3];
    current_tip_loc[1] = (Coil_Loc[1]*2) - Coil_Loc[4];
    current_tip_loc[2] = (Coil_Loc[2]*2) - Coil_Loc[5];
    current_tip_loc[3] = 1; // add extra element as likely/unlikely indicator; positive (1) by default

    bool likely; // flag for likelihood test
    if (i > 0) // only apply test after first sample
    {
        _delta_loc = calc_delta(); // call CompTips to calculate distance between current and previous location
        likely = realtest(_delta_loc); // test whether distance is likely/unlikely
        if (likely == false)
        {
            // If not likely, use for loop to replace current location with previous
            for (int k = 0; k < 3; k++)
            {
                current_tip_loc[k] = last_tip_loc[k];
            }
            current_tip_loc[3] = 0; // Also,set indicator to negative (0)
        }
    }
    // Use for loop to store current  location in previous location array
    for (int k = 0; k < 3; k++)
    {
        last_tip_loc[k] = current_tip_loc[k];
    }
    return;
}
// Function for computing distance between current and previous tip locations
float Catheter :: calc_delta()
{
    float _delta_loc, dx, dy, dz; // initialize variables
    // Find difference between tip current and previous tip coordinates
    dx = current_tip_loc[0] - last_tip_loc[0];
    dy = current_tip_loc[1] - last_tip_loc[1];
    dz = current_tip_loc[2] - last_tip_loc[2];

    _delta_loc = sqrt(pow(dx, 2) + pow(dy, 2) + pow(dz, 2)); // calculate distance between locations
    return _delta_loc;
}
