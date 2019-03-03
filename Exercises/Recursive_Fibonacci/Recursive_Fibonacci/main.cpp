#include <iostream>
using namespace std;

// function prototype
int Fib (int n);

int main()
{
    int n;
    cout << "Enter number:" << endl;
    cin >> n;
    cout << n << "th Fibonacci number is " << Fib(n) << endl;
    return 0;
}

// function body
int Fib (int n)
// recursive (& not efficient) implementation of Fibonacci numbers
{
    if ((n == 0) || (n == 1))
        return 1;
    else
        return (Fib(n-1) + Fib(n-2));
}
