//
// Created by maciej on 15.03.18.
//
#include "GreatestProduct.h"

int main(){
    using namespace std;
    vector<int> tab= {1,3,4,5,1,23,2,31};
    int result;
    int k = 2;
    result = GreatestProduct(tab, k);
    cout << result << endl;
    return 0;
}
