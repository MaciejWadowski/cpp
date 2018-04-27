#include <iostream>
#include "../header_files/Matrix.h"
#include "../header_files/Lists.h"
#include "../header_files/Para.h"
#include "Lists.cpp"
using namespace std;



int main() {
    List<Matrix> list, list2, list3;
    cin >> list >> list >> list;
    cin >> list2 >> list2;
    list3 = list + list2;
    list3 = list + list2;
    cout << list3;
    return 0;
}