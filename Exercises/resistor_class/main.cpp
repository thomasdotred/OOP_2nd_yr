#include <iostream>

using namespace std;

int main()
{
    // Program to find the remainder of (2+3*3)/n
    float n, ans, math, rem;
    cout << "Enter  number: \n";
    cin >> n;
    math = (2+3*3)/n;
    //rem = (2+3*3)%n;
    cout <<"the answer to the equation is " << math;

    return 0;
}
