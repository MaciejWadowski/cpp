//
// Created by wadziuxxx on 4/5/18.
//

#ifndef JIMP_EXERCISES_SQUARE_H
#define JIMP_EXERCISES_SQUARE_H
#include "Point.h"

#include "Point.h";
namespace geometry
{
    class Square {
    public:
        Square(Point A, Point B, Point C, Point D);
        double Circumference() const;
        double Area() const;

    private:
        Point _A, _B, _C, _D;
    };
}

#endif //JIMP_EXERCISES_SQUARE_H
