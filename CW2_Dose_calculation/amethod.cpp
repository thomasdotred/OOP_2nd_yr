#include "amethod.h"
#include <iostream>
using namespace std;

double amethod(double& dose_size,double dose_inc[])
{

    int dose_level,tox_num;
    dose_level = 0;
    //dose level will be used to select which increment to use:
    //ie. 1==> 167%, 2==> 150%, ...etc.
    tox_num = 0;

    //while Number of People with toxic effects is less than two, carry out the next round of tests
    while (dose_size > 15.1)
    {
        cout<<"test cohort of 3 patients"<<endl;
        cout << "Enter the number of patients who experienced significant toxicity: " << endl;
        cin >> tox_num;

        //if toxic in first test, the dose size is too big
                if (dose_level == 0 && tox_num != 0)
        {
            cout << "initial dose size too big" <<endl;
            break;
        }

        switch (tox_num)
        {
        case 0:
            //All clear - go ahead with increasing dose size
            //Increase increment level by one
            dose_level = dose_level +1;
            //cap the increases at 33% after 4th increase
            if (dose_level > 4)
            {
                dose_level = 4;
            }
            // apply percentage increase
            dose_size = dose_size + 0.5;
            cout << "new dose size: " << dose_size <<endl;
            continue;

        case 1:
            //if one of the cohort has toxic effects, repeat the round without altering dose size
            cout << dose_size<<endl;
            continue;
        }
    }

    cout<<"3,3 method done with "<< tox_num << " patients experiencing significant toxicity"<< endl;
    //return previous level by dividing by the most recent increase
    cout<<"dose level is "<< dose_level <<endl;
    return dose_size;
}


double bmethod(double &dose_size ,double dose_inc[])

{
    int dose_level,cohort_size,tox_num;
    dose_level = 0;
    cohort_size = 2;
    tox_num = 0;

    //while fewer than 2 patients have toxic effects, continue with test
    while (tox_num < 2)
    {
        //instruct what cohort size and dose size to use and input number of patients with toxic effects
        cout<<"test cohort of "<< cohort_size <<" patients  with "<<dose_size<<"mg/kg"<<endl;
        cout << "Enter the number of patients who experienced significant toxicity: " << endl;
        cin >> tox_num;

        //if toxic in first test, the dose size is too big
        if (dose_level == 0 && tox_num != 0)
        {
            cout << "initial dose size too big" <<endl;
            break;
        }



        switch (tox_num)
        {
        case 0:
            //all clear - increase dose size
            dose_level = dose_level +1;
            if (dose_level >4)
            {
                dose_level = 4;
            }
            dose_size = dose_size*dose_inc[dose_level];
            //reassign cohort size to 2
            cohort_size = 2;
            cout<<"new dose size: "<<dose_size<<endl;
            continue;
        case 1:
            //one with toxic effects - repeat without changing dose size and increasing cohort size to 4
            cohort_size = 4;
            cout<<"new dose size: "<<dose_size<<endl;
            continue;
        case 2:
            break;

        }
    }

    cout << dose_size <<"mg/kg"<< endl;
    cout<<"2,4 method done with "<< tox_num << " patients experiencing significant toxicity"<< endl;

    // return recommended dose size by finding the dose size before the toxic effects were found
    return dose_size/dose_inc[dose_level];
}
