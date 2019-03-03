#include <iostream>
#include <string>
using namespace std;

// overloaded functions for formatted printing
void pretty_print (int x);
void pretty_print (string x);

int main()
{
    int a = 33;
    pretty_print(a);
    string str = "hello"; // a string is a sequence of characters - we'll cover this later in module ...
    pretty_print(str);
    return 0;
}

void pretty_print (int x)
// formatted print function
{
    cout << "Integer: " << x << endl;
}

void pretty_print (string x)
// formatted print function
{
    cout << "String: " << x << endl;
}
