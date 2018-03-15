//
// Created by maciej on 11.03.18.
//

#include "Array2D.h"
using namespace std;
int main(){
    int rows,columns, **array;
    cin >> rows >> columns;
    array = Array2D(rows, columns);
    DeleteArray2D(array, rows, columns);
    return 0;
}