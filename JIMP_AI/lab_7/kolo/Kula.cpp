//
// Created by wadziuxxx on 5/17/18.
//

#include "Kula.h"

Kula::Kula() : Kolo(){
    z = 0;
}

Kula::Kula(double x_, double y_, double z_, double r_) : Kolo(x_,y_,r_) {
    z = z_;
}

double Kula::Pole() {
    return 3.14*(4./3.)*r*r*r;
}
