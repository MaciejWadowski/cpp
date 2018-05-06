#include "BigNumbers.h"
//konstr, destr, =, +, >>, <<
//jedna cyfra to conajmniej 1 bajt
using namespace std;

int main() {
    BigNumbers o1{"00000005357865767"}, o2{"213121212"}, o3,o4,o5;
    cout << o1 << endl;
    cout << o2 << endl;
    o3 = o1 + o2;
    cout << o3 << endl;
    cout << o4 << endl;
    o3 = o5 + o1;
    o3 = o1 + o5;
    cout << o3 << endl;
    cin >> o4;
    cout << o4;
    return 0;
}