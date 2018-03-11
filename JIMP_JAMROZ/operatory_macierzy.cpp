#include <iostream>

using namespace std;
// 1.zwolnic pamiec dla drugiej strony
// 2.zarezerwowac pamiec
// 3.przepisac pamiec(zawartosc) 01 -> this; return *this;
// ws = NULL, this->ws = NULL
// OGOLNIE DOKONCZYC DZIALANIA ( a = b = c, c = a + b)
class Macierze{
private:
    friend ostream &operator << (ostream &s1, Macierze &o1); //musza byc funkcjami zaprzyjaznionymi, bo po lewej stronie jest cout, cin
    friend istream &operator >> (istream &s1, Macierze &o1);
    double *ws;
    int rozmiar;
public:
    Macierze(){
        ws = nullptr;
        rozmiar = 0;
    }
    Macierze(const Macierze &o1){  // kopiujacy konstruktor, potrzebny przy dodawaniu
        rozmiar = o1.rozmiar;
        ws = new double[o1.rozmiar*o1.rozmiar];
        for ( int i = 0; i < rozmiar*rozmiar; i++) ws[i] = o1.ws[i];
    }
    ~Macierze(){
        if ( ws != nullptr) delete [] ws;
        ws = nullptr;         //potrzebne, jak nie ustawie ws na nullptr to wyciek pamieci(linux)
    }

    Macierze &operator = (const Macierze &o1) {
        if (&o1 != this) {   //sprawdzam czy to nie jest ta sama macierz...
            if (this->ws == nullptr) {
                this->ws = new double[o1.rozmiar * o1.rozmiar];
                this->rozmiar = o1.rozmiar;            //bez tego wyciek pamieci(jak na lekci z dwoma destruktorami)
                for (int i = 0; i < o1.rozmiar * o1.rozmiar; i++) this->ws[i] = o1.ws[i];
            } else if (this->rozmiar != o1.rozmiar) {  // jezeli rozne rozmiary to redefiniuje
                delete [] this->ws;
                this->ws = new double[o1.rozmiar * o1.rozmiar];
                this->rozmiar = o1.rozmiar;
                for (int i = 0; i < o1.rozmiar * o1.rozmiar; i++) this->ws[i] = o1.ws[i];
            }
            return *this;
        }
        return *this;
    }
    Macierze operator + (const Macierze &o1){ // jak wczesniej byl operator referencji, byl blad bo zmienna sie ulatniala i wskaznik result wskazywal na NULL
        if (this->rozmiar != o1.rozmiar){  // no tu sie nie da co
            return *this;
        }
        else{
            Macierze wynik = Macierze(*this);  // kopia macierzy po lewej stronie
            for( int i = 0; i < o1.rozmiar*o1.rozmiar; i++) this->ws[i] += o1.ws[i];
            return *this;  //return by value
        }
    }
};

istream	&operator >> (istream &s1, Macierze &o1){
    s1 >> o1.rozmiar;
    o1.ws = new double[o1.rozmiar * o1.rozmiar];
    for ( int i = 0; i < o1.rozmiar*o1.rozmiar; i++) o1.ws[i] = i+1;
    return s1;
}

ostream &operator << (ostream &s1, Macierze &o1){
    if (o1.ws != nullptr){
        for ( int i = 0, j = 1; i < o1.rozmiar * o1.rozmiar; i++, j++){
            s1 << o1.ws[i] << " ";
            if ( j == o1.rozmiar ){
                s1 << endl;
                j = 0;
            }
        }
    }
    return s1;
}

int main(){
    Macierze zm;
    cin >> zm;
    cout << zm;
    zm.~Macierze();
    zm.~Macierze();
    Macierze o1, o2, o3, o4;
    cin >> o1;
    cout << o1;
    cin >> o2;
    cout << o2;
    o3 = o2 = o1;
    cout << o3 << o2 << o1;
    o3 + o2;
    cout << o3;
    cout << o2;
    o4 = o1 + o2;
    cout << o4;
    return 0;
}