//
// Created by wadziuxxx on 5/17/18.
//

#ifndef JIMP_EXERCISES_KULA_H
#define JIMP_EXERCISES_KULA_H

#include "Kolo.h"

class Kula : public Kolo{
public:
    Kula();

    Kula(double x_, double y_ , double z_, double r_);

    double Pole() override;
private:
    double z;
};


#endif //JIMP_EXERCISES_KULA_H
