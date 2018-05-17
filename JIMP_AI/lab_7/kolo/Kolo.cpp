//
// Created by wadziuxxx on 5/17/18.
//

#include "Kolo.h"

Kolo::Kolo() {
    x = 0;
    y = 0;
    r = 0;
}

Kolo::Kolo(double x_, double y_, double r_) {
    x = x_;
    y = y_;
    r = r_;
}

double Kolo::Pole() {
    return 3.14*r*r;
}
