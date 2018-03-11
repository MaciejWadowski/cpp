//
// Created by maciej on 11.03.18.
//

#include "MultiplicationTable.h"
void MultiplicationTable(int tab[][10]){
    int i, j;
    for (i = 1; i <= 10; i++)
        for(j = 1; j <= 10; j++)
            tab[i - 1][j - 1] = i*j;

    for (i = 0; i<=9 ; i++){
        for(j = 0; j<=9; j++)
            std::cout << tab[i][j] << "  ";
        std::cout << std::endl;
    }
}