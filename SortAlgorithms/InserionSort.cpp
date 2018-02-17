#include <iostream>
#include <ctime>
//Stabilne, W miejscu, op O(n), normalnie O(n^2)
void InsertionSort(int tab[], int length);
void swap(int &a, int &b);

int main() {
    int n, i;
    std::cout << "Enter a number of elements: ";
    std::cin >> n;
    int *tab = new int [n];
    srand(time(NULL));

    for (i = 0 ; i < n; i++) tab[i] = std::rand()%100+1;

    InsertionSort(tab,n);

    for ( i = 0; i < n; i++) std::cout << tab[i] << " ";

    delete [] tab;
    return 0;
}

void InsertionSort(int tab[], int length){
    int i, j, tmp;

    for (i = length - 1; i >= 1; i--){
        tmp = tab[i];
        if (tab[i-1] > tab[i]){
            swap(tab[i-1], tab[i]);
            tmp = tab[i];
        }

        j = i+1;
        while ((j < length) && (tmp > tab [j])){
            swap(tab[j-1], tab[j]);
            j++;
        }
    }

}

void swap(int &a, int &b){
    int tmp = a;
    a = b;
    b = tmp;
}