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
    Macierze(int _rozmiar){
        rozmiar = _rozmiar;
        ws = new double[rozmiar*rozmiar];
        for(int i = 0 ; i< rozmiar*rozmiar; i++) ws[i] = 0;
    }
    Macierze(int _rozmiar, int wartosc){
        rozmiar = _rozmiar;
        ws = new double[rozmiar*rozmiar];
        for(int i = 0; i<rozmiar*rozmiar; i++) ws[i] = wartosc;
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
                delete[] this->ws;
                this->ws = new double[o1.rozmiar * o1.rozmiar];
                this->rozmiar = o1.rozmiar;
                for (int i = 0; i < o1.rozmiar * o1.rozmiar; i++) this->ws[i] = o1.ws[i];
            }
        }
        return *this;
    }
    Macierze operator + (const Macierze &o1){ // jak wczesniej byl operator referencji, byl blad bo zmienna sie ulatniala i wskaznik result wskazywal na NULL
        if (this->rozmiar != o1.rozmiar){  // no tu sie nie da co
            return *this;
        }
        else{
            Macierze wynik = Macierze(*this);  // kopia macierzy po lewej stronie
            for( int i = 0; i < o1.rozmiar*o1.rozmiar; i++) wynik.ws[i] += o1.ws[i];
            return wynik;  //return by value
        }
    }
    Macierze operator - (const Macierze &o1) {
        if (rozmiar != o1.rozmiar) return *this;
        Macierze wynik = Macierze(*this);
        for (int i = 0; i < rozmiar * rozmiar; i++) wynik.ws[i] -= o1.ws[i];
        return wynik;
    }
    Macierze operator * (const Macierze &o1) {
        if (rozmiar != o1.rozmiar) return *this;
        Macierze wynik = Macierze(*this);
        int rows = 0, count = 0, result = 0, column = 0;
        while (true){
            for(int i = rozmiar*rows, j = column; i <rozmiar*rows + rozmiar; i++, j += rozmiar) result += ws[i]*o1.ws[j];
            column++;
            wynik.ws[count] = result;
            result = 0;
            count++;
            if(column == rozmiar) {
                rows++;
                column = 0;
            }
            if (rows == rozmiar) break;
        }
        return wynik;
    }
    bool operator == (const Macierze& s1){
        if (rozmiar != s1.rozmiar) return false;
        for(int i = 0; i < rozmiar*rozmiar; i++)
            if(ws[i] != s1.ws[i]) return false;
        return true;
    }

    bool operator != (const Macierze& s1){
        if (rozmiar != s1.rozmiar) return true;
        for(int i = 0; i < rozmiar*rozmiar; i++)
            if(ws[i] != s1.ws[i]) return true;
        return false;
    }

    bool operator > (const Macierze &s1){
        double wynik1 = 0, wynik2 = 0;
        for(int i = 0 ; i< rozmiar*rozmiar; i++) wynik1 += ws[i];
        for(int i = 0; i < s1.rozmiar*s1.rozmiar; i++) wynik2 += s1.ws[i];
        if ( wynik1 > wynik2) return true;
        else return false;
    }
    bool operator < (const Macierze &s1){
        double wynik1 = 0, wynik2 = 0;
        for(int i = 0 ; i< rozmiar*rozmiar; i++) wynik1 += ws[i];
        for(int i = 0; i < s1.rozmiar*s1.rozmiar; i++) wynik2 += s1.ws[i];
        if ( wynik1 < wynik2) return true;
        else return false;
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
    Macierze zm, zm2(3,3), zm3;
    cin >> zm;
    cout << zm;
    cout << zm2;
    zm3 = zm*zm2;
    cout << zm3;
    return 0;
