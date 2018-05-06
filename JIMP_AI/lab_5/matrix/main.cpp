//
// Created by wadziuxxx on 4/21/18.
//

#include "Matrix.h"
using namespace algebra;

int main(){
    Matrix m1{{{1.0i},{1.0i}}, {{1.0i},{2.0i}}};
    std::cout << m1.Pow(2).Print();
    return 0;
}