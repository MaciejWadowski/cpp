//
// Created by wadziuxxx on 5/17/18.
//

#include "Kula.h"
#include "Kolo.h"
#include <iostream>

int main(){
    Kolo o1(1,1,1);
    Kula o2(0,0,0,10);
    std::cout << o1.Pole() << " -- " << o2.Pole() << std::endl;

}