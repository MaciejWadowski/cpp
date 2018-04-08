//
// Created by wadziuxxx on 4/5/18.
//

#include "Square.h"
#include "Point.h"
#include <cmath>

using namespace std;
using namespace geometry;

Square::Square(Point A, Point B, Point C, Point D)
{
    _A = A;
    _B = B;
    _C = C;
    _D = D;
}
double Square::Circumference() const
{

    if(_A.Point::Distance(_C) == _B.Point::Distance(_D))
        return _A.Point::Distance(_B)*4;

    return 0;
}
double Square::Area() const
{
    if(_A.Point::Distance(_C) == _B.Point::Distance(_D))
        return _A.Point::Distance(_B)*_A.Point::Distance(_B);

    return 0;
}