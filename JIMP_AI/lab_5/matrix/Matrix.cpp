//
// Created by wadziuxxx on 4/21/18.
//

#include "Matrix.h"

using std::complex;
using namespace algebra;
using std::string;


Matrix::Matrix(size_t rows, size_t columns){
    size.first = rows;
    size.second = columns;
    if(size.first <= 0 || size.second <= 0) matrix = nullptr;
    else {
        matrix = new std::complex<double> *[rows];
        for (int i = 0; i < rows; i++) matrix[i] = new std::complex<double>[columns];
    }
}

Matrix::Matrix() {
    matrix = nullptr;
    size.first = 0;
    size.second = 0;
}

Matrix::Matrix(const Matrix &other) {
    size.first = other.size.first;
    size.second = other.size.second;
    if(size.first == 0 || size.second == 0) matrix = nullptr;
    else {
        matrix = new std::complex<double> *[size.first];
        for (int i = 0; i < size.first; i++) matrix[i] = new std::complex<double>[size.second];

        for (int i = 0; i < size.first; i++)
            for (int j = 0; j < size.second; j++)
                matrix[i][j] = other.matrix[i][j];
    }
}


Matrix::~Matrix(){
    if(matrix != nullptr) {
        for (int i = 0; i < size.first; i++) delete[] matrix[i];
        delete[] matrix;
    }
    matrix = nullptr;
}

Matrix::Matrix(const char *matrix_str) {
    size_t rows_ = 0, columns_ = 0;

    for(int i = 1; i < strlen(matrix_str); i++) if(matrix_str[i] == ';') rows_++;
    for(int i = 1; i < strlen(matrix_str) && matrix_str[i] != ';';i++) if(isspace(matrix_str[i])) columns_++;

    size.first = rows_;
    size.second = columns_;

    matrix = new std::complex<double>*[rows_];
    for(int i = 0; i < rows_; i++) matrix[i] = new std::complex<double>[columns_];

    int j = 0, k = 0;
    bool real_or_not = true;
    std::complex <double> value;
    for(int i = 1; i < strlen(matrix_str) && matrix_str[i] !=']'; i++){
        if(matrix_str[i] == ';'){
            j++;
            k=0;
            real_or_not = true;
        }
        else if(isdigit(matrix_str[i]) && real_or_not){
            double real_val = 0;
            while(isdigit(i)) real_val = real_val*10 + matrix_str[i] - '0';
        }
        else if(matrix_str[i] == 'i') real_or_not = false;
    }
}

void Matrix::setElement(size_t x, size_t y, std::complex<double> value) {
    if(x < size.first && y< size.second && x >=0 && y >= 0) matrix[x][y] = value;
}

std::complex<double> Matrix::getElement(size_t x, size_t y) {
    if(x < size.first && y< size.second && x >=0 && y >= 0) return matrix[x][y];
    else return {0,0};
}

Matrix::Matrix(std::initializer_list<std::vector<std::complex<double>>> matrix_) {
    size.first = matrix_.size();
    size.second = matrix_.begin()->size();
    if(size.first <= 0 || size.second <= 0) matrix = nullptr;
    else {
        matrix = new std::complex<double> *[size.first];
        for (int i = 0; i < size.first; i++) matrix[i] = new std::complex<double>[size.second];

        std::vector<std::complex<double>> elements[size.first];
        int j = 0;
        for (auto i : matrix_) {
            elements[j] = i;
            j++;
        }
        for (int i = 0; i < size.first; i++)
            for (int j = 0; j < size.second; j++)
                matrix[i][j] = elements[i][j];
    }
}

string Matrix::Print() const{
    if(matrix == nullptr ) return "[]";
    else {
        string output = "[";
        for (int i = 0; i < size.first; i++) {
            for (int j = 0; j < size.second; j++) {
                std::ostringstream ss;
                if(matrix[i][j].real())
                    ss << matrix[i][j].real();
                else ss << '0';
                ss << 'i';
                if(matrix[i][j].imag())
                    ss << matrix[i][j].imag();
                else ss << '0';
                ss << ", ";
                string str = ss.str();
                output += str;
            }
            output.pop_back();
            output.pop_back();
            output += "; ";
        }
        output.pop_back();
        output.pop_back();
        output += ']';
        return output;
    }
}

std::pair<size_t, size_t> Matrix::Size() {
    return size;
}

Matrix Matrix::Add(const Matrix &other) const{
    if(size.first == other.size.first && size.second == other.size.second){
        Matrix result(*this);
        for(int i = 0; i < size.first; i++)
            for(int j =0 ; j < size.second; j++)
                result.matrix[i][j] += other.matrix[i][j];
        return result;
    }
    else{
        Matrix ret{0,0};
        return ret;
    }
}

Matrix Matrix::Pow(int power)const {
    if(power == 0){
        Matrix result{size.first, size.second};

        for(int i = 0; i < size.first; i++){
            for(int j = 0; j < size.second;j++){
                if(i == j) result.matrix[i][j] = {1.0, 0.0};
                else result.matrix[i][j] = {0.0,0.0};
            }
        }
        return result;
    }
    else if(size.first != size.second){
        Matrix ret{0,0};
        return ret;
    }
    else {
        Matrix result{*this};
        for (int i = 1; i < power; i++)
            result = result.Mul(*this);
        return result;
    }
}

Matrix Matrix::Mul(const Matrix &other)const {
    if(size.second == other.size.first){
        Matrix result{size.first,other.size.second};
        std::complex<double> tmp{0,0};
        for (int i=0;i<size.first;i++)
        {
            for (int s=0;s<other.size.second;s++)
            {
                 tmp = {0,0};
                for(int k=0; k < size.second; k++)
                {
                    tmp+=matrix[i][k]*other.matrix[k][s];

                }
                result.matrix[i][s] = tmp;

            }
        }
        return result;
    }
    else{
        Matrix ret{0,0};
        return ret;
    }
}

Matrix Matrix::Sub(const Matrix &other) const {
    if(size.first == other.size.first && size.second == other.size.second){
        Matrix result(*this);
        for(int i = 0; i < size.first; i++)
            for(int j =0 ; j < size.second; j++)
                result.matrix[i][j] -= other.matrix[i][j];
        return result;
    }
    else{
        Matrix ret{0,0};
        return ret;
    }
}

Matrix &Matrix::operator=(const Matrix &other) {
    if(this == &other) return *this;
    if(size.first != other.size.first && size.second != other.size.second){
        for(int i = 0; i< size.first; i++) delete[] matrix[i];
        delete [] matrix;
        size.first= other.size.first;
        size.second = other.size.second;
    }
    for(int i = 0; i < size.first;i++){
        for(int j = 0; j < size.second; j++){
            matrix[i][j] = other.matrix[i][j];
        }
    }
}
