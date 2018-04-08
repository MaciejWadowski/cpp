//
// Created by Maciej on 08.04.2018.
//

#include "Matrix.h"

Matrix::Matrix(){
    ws = nullptr;
    size = 0;
}

Matrix::Matrix(int _size){
    size = _size;
    ws = new double[size*size];
    for(int i = 0 ; i< size*size; i++) ws[i] = 0;
}

Matrix::Matrix(int _size, int value){
    size = _size;
    ws = new double[size*size];
    for(int i = 0; i<size*size; i++) ws[i] = value;
}

Matrix::Matrix(const Matrix &o1){  // kopiujacy konstruktor, potrzebny przy dodawaniu
    size = o1.size;
    ws = new double[o1.size*o1.size];
    for ( int i = 0; i < size*size; i++) ws[i] = o1.ws[i];
}

Matrix::~Matrix(){
    if (ws) delete [] ws;
    ws = nullptr;         //potrzebne, jak nie ustawie ws na nullptr to wyciek pamieci(linux)
}

Matrix  &Matrix::operator = (const Matrix &o1) {
    if (&o1 != this) {   //sprawdzam czy to nie jest ta sama macierz...
        if (this->ws != nullptr) delete[]this->ws;  // jezeli rozne rozmiary to redefiniuje
        this->ws = new double[o1.size * o1.size];
        this->size = o1.size;
        for (int i = 0; i < o1.size * o1.size; i++) this->ws[i] = o1.ws[i];
    }
    return *this;
}

Matrix Matrix::operator + (const Matrix &o1){ // jak wczesniej byl operator referencji, byl blad bo zmienna sie ulatniala i wskaznik result wskazywal na NULL
    if (this->size != o1.size){  // no tu sie nie da co
        return *this;
    }
    else{
        Matrix result = Matrix(*this);  // kopia macierzy po lewej stronie
        for( int i = 0; i < o1.size*o1.size; i++) result.ws[i] += o1.ws[i];
        return result;  //return by value
    }
}

Matrix Matrix::operator - (const Matrix &o1) {
    if (this->size != o1.size) return *this;
    Matrix result_matrix = Matrix(*this);
    for (int i = 0; i < this->size * this->size; i++) result_matrix.ws[i] -= o1.ws[i];
    return result_matrix;
}

Matrix Matrix::operator * (const Matrix &o1) {
    if (this->size != o1.size) return *this;
    Matrix result_matrix = Matrix(*this);
    int rows = 0, count = 0, result = 0, column = 0;
    while (true){
        for(int i = this->size*rows, j = column; i <this->size*rows + this->size; i++, j += this->size) result += this->ws[i]*o1.ws[j];
        column++;
        result_matrix.ws[count] = result;
        result = 0;
        count++;
        if(column == this->size) {
            rows++;
            column = 0;
        }
        if (rows == this->size) break;
    }
    return result_matrix;
}

bool Matrix::operator == (const Matrix& s1){
    if (size != s1.size) return false;
    for(int i = 0; i < size*size; i++)
        if(ws[i] != s1.ws[i]) return false;
    return true;
}

bool Matrix::operator != (const Matrix &s1){
    if (size != s1.size) return true;
    for(int i = 0; i < size*size; i++)
        if(ws[i] != s1.ws[i]) return true;
    return false;
}

bool Matrix::operator > (const Matrix &s1){
    double result_1 = 0, result_2 = 0;
    for(int i = 0 ; i< size*size; i++) result_1 += ws[i];
    for(int i = 0; i < s1.size*s1.size; i++) result_2 += s1.ws[i];
    return result_1 > result_2;
}

bool Matrix::operator < (const Matrix &s1){
    double reulst_1 = 0, result_2 = 0;
    for(int i = 0 ; i< size*size; i++) reulst_1 += ws[i];
    for(int i = 0; i < s1.size*s1.size; i++) result_2 += s1.ws[i];
    return reulst_1 < result_2;
}

istream	&operator >> (istream &s1, Matrix &o1){
    if(o1.ws != nullptr) delete [] o1.ws;
    s1 >> o1.size;
    o1.ws = new double[o1.size * o1.size];
    for ( int i = 0; i < o1.size*o1.size; i++) s1 >> o1.ws[i];
    return s1;
}

ostream &operator << (ostream &s1, Matrix &o1){
    if (o1.ws != nullptr){
        for ( int i = 0, j = 1; i < o1.size * o1.size; i++, j++){
            s1 << o1.ws[i] << " ";
            if ( j == o1.size ){
                s1 << endl;
                j = 0;
            }
        }
    }
    return s1;
}