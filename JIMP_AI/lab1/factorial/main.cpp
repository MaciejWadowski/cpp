#include <iostream>
#include "factorial.h"
using namespace std;
int main() {
    int n, result;
    cin >> n;
    result = factorial(n);
    cout << result << endl;
    result = factorial_reku(n);
    cout << result << endl;
    return 0;
}