//
// Created by wadziuxxx on 5/17/18.
//

#ifndef JIMP_EXERCISES_KOLO_H
#define JIMP_EXERCISES_KOLO_H


class Kolo {
public:
    Kolo ();

    Kolo (double x_, double y_, double r_);

    virtual double Pole();

protected:
    double x, y;
    double r;
};


#endif //JIMP_EXERCISES_KOLO_H
