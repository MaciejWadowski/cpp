#include <iostream>

void MultiplicationTable(int tab[][10]);
void PrintTable(int tab[][10]);


int main() {
    int tab[10][10];
    MultiplicationTable(tab);
    PrintTable(tab);
    return 0;
}

void MultiplicationTable(int tab[][10]){
    int i, j;
    for (i = 1; i <= 10; i++)
        for(j = 1; j <= 10; j++)
            tab[i][j] = i*j;
}

void PrintTable(int tab[][10]){
    int i, j;
    for (i = 1; i<=10 ; i++){
        for(j = 1; j<=10; j++)
            std::cout << tab[i][j] << "  ";
        std::cout << std::endl;
    }
}