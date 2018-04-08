#include "ListOperators.h"
using namespace std;

int main() {
    class List list, list2, list3, list4, list5;
    for(int i = 0; i < 5; i++) cin >> list;
    cout << list << endl;
    for(int i = 0; i < 6; i++) cin >> list2;
    list3 = list + list2;
    cout << list3 << endl;
    list3 = list2 + list;
    cout << list3 << endl;
    list = list2 + list5;
    cout << list << endl;
    list = list4 + list5;
    cout << list << "nothing" << endl;
    return 0;
}