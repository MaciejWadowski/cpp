//
// Created by Maciej on 09.04.2018.
//

#ifndef MATRIX_MATRIX_H
#define MATRIX_MATRIX_H
#include <iostream>
using namespace std;

class Matrix{
public:
    Matrix();
    Matrix(int _size);
    Matrix(int _size, int value);
    Matrix(const Matrix &o1);
    ~Matrix();

    Matrix &operator = (const Matrix &o1);
    Matrix operator + (const Matrix &o1);
    Matrix operator - (const Matrix &o1);
    Matrix operator * (const Matrix &o1);
    bool operator == (const Matrix& s1);
    bool operator != (const Matrix &s1);
    bool operator > (const Matrix &s1);
    bool operator < (const Matrix &s1);

private:
    friend ostream &operator << (ostream &s1, Matrix &o1); //musza byc funkcjami zaprzyjaznionymi, bo po lewej stronie jest cout, cin
    friend istream &operator >> (istream &s1, Matrix &o1);
    double *ws;
    int size;
};


#endif //MATRIX_MATRIX_H
