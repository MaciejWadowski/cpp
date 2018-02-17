#include <iostream>
#include <ctime>
// nie w miejscu, stabilne, )(nlog(n))
void Merge(int tab[],int,int,int);
void MergeSort(int tab[], int, int);

int main() {
    int i, n;
    std::cout << "Enter a number: ";
    std::cin >> n;
    auto *tab = new int [n];

    for ( i = 0; i < n; i++) tab[i] = rand()%100 + 1;

    MergeSort(tab,0,n-1);

    for ( i = 0; i < n; i++) std::cout << tab[i] << " ";

    delete [] tab;
    return 0;
}

void MergeSort(int tab[], int ip, int ik){   // ip index poczatkowy starego podzb, ik index ost elemntu, w najstarszym
    int is = (ip + ik + 1)/2;                // is - index startowy starszego podzb

    if (is - ip > 1 ) MergeSort(tab,ip,is-1);
    if (ik - is > 0 ) MergeSort(tab,is,ik);

    Merge(tab,ip,is,ik);
}

void Merge(int tab[], int ip, int is, int ik){
    int i2,i1,i;
    int p[ik];
    i1 = ip;
    i2 = is;
    for ( i = ip; i <= ik; i++){
        if((i1 == is) || ((i2 <= ik) && (tab[i1] > tab[i2]))) {
            p[i] = tab[i2];
            i2++;
        }
        else{
            p[i] = tab[i1];
            i1++;
        }
    }
    for ( i = ip; i <= ik; i++) tab[i] = p[i];
}