#include <iostream>
#include "Matrix.h"

int main() {
    Matrix a, b ,c;
    cin >> a >> b;
    c = a*b;
    cout << c;
    c = a+b;
    cout << c;
    return 0;
}