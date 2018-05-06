//
// Created by wadziuxxx on 4/21/18.
//

#ifndef JIMP_EXERCISES_MATRIX_H
#define JIMP_EXERCISES_MATRIX_H
#include <string>
#include <complex>
#include <cstring>
#include <vector>
#include <iostream>

namespace algebra {
    class Matrix {
    public:
        Matrix();
        Matrix( size_t, size_t);
        Matrix(const Matrix &other);
        Matrix &operator = (const Matrix &other);
        Matrix(const char *matrx_str);
        Matrix(std::initializer_list<std::vector<std::complex<double>>> matrix_);
        void setElement(size_t rows, size_t columns, std::complex<double> value);
        std::complex<double> getElement(size_t rows, size_t columns);
        std::pair<size_t,size_t> Size();
        std::string Print()const;
        Matrix Add(const Matrix &other)const;
        Matrix Mul(const Matrix &other)const;
        Matrix Sub(const Matrix &other)const;
        Matrix Pow(int)const;
        ~Matrix();
    private:
        std::complex<double> **matrix;
        std::pair<size_t, size_t> size;
    };
}


#endif //JIMP_EXERCISES_MATRIX_H
