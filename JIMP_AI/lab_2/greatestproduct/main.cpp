//
// Created by maciej on 15.03.18.
//
#include "GreatestProduct.h"

int main(){
    using namespace std;
    vector<int> tab= {-11, 8, 2, 9, -9, 8, 5, -1,};
    int result;
    int k = 2;
    result = GreatestProduct(tab, k);
    cout << result << endl;
    return 0;
}
