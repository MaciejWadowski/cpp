//
// Created by Maciej on 14.04.2018.
//

/*#ifndef SZABLONY_PARA_H
#define SZABLONY_PARA_H
#include <iostream>
using namespace std;

template <class T>
class Para{
public:
    T x, y;
    Para<T>(){}
    Para<T>(const Para<T> &o1);

    Para<T> &operator = (const Para<T> &o1);

    friend Para<T> &operator + (Para<T> &o1, Para<T> &o2){ {
            static Para<T> temp;
            temp.x = o1.x + o2.x;
            temp.y = o1.y + o2.y;
            return temp;
        }

};
template <class T>
istream & operator >> (istream &s1, Para<T> &o1);

template <class T>
ostream & operator << (ostream &s1, Para<T> &o1);
#endif //SZABLONY_PARA_H
*/