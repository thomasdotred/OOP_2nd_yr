#include <iostream>
using namespace std;

// prototypes
void test_by_value (int);
void test_by_reference (int&);

int main()
{
    int x;
    x = 5;

    cout << "x = " << x << endl;

    test_by_value (x);
    cout << "x = " << x << endl;

    test_by_reference (x);
    cout << "x = " << x << endl;

    return 0;
}

void test_by_value (int n)
{
    n++;
}

void test_by_reference (int& n)
{
    n++;
}

