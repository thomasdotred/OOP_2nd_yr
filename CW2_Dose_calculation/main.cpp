#include <iostream>
#include "amethod.h"

//#include <string>
using namespace std;

int main(){

//define variable types and initialise dose increments using 'common way of dose escalation' according to  percentages provided in question
    double dose_size,init_dose_size;
    char method;

    double dose_inc[5] = {1, 1.67, 1.5, 1.4, 1.33};
    //select dose size
    cout << "enter initial dose size (mg/kg)" << endl;
    cin >> dose_size;
    init_dose_size = dose_size;
    //select method
    cout << "select [A] for 3 + 3 rule and [B] for 2 + 4 rule" << endl;
    cin >> method;


    switch(method)
        {

            case 'a':
            case 'A':

                //begin 3 + 3 method
                dose_size = amethod(dose_size,dose_inc);

                    break;

            case 'b':
            case 'B':
                //begin 2 + 4 method
                dose_size = bmethod(dose_size,dose_inc);
                    break;
                //error - enter a or b
            default:
                cout <<"Error: please enter method a or b" << endl;
        }
        //output recommended dose for phase II trials if the dose size was increased
        if (dose_size > init_dose_size){
        cout << "Recommended dose for Phase II is: " << dose_size <<"mg/kg" << endl;
        }


return 0;
}
