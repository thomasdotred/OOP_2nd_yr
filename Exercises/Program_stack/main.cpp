#include <iostream>

using namespace std;

int f1 (int);
int f2 (int);

int main () {
    int x = 3;
    cout << "f1(f2(3)) = " << f1(x) << endl;
    return 0;
}

int f1 (int a) {
    int p = a * 3;
    return f2(p + 2);
}

int f2 (int b) {
    int q = b * 2;
    return q - 1;
}
