//
// Created by wadziuxxx on 4/7/18.
//

#include "Name.h"


int main(){
    model::Name maciek{"First\t\tSecond\t\tThird"};
    std::cout << maciek.FirstName();
    return 0;
}