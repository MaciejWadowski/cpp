#include <iostream>
using namespace std;
// konstruktor, destruktor
// operatory wejscia wyjscia
// + dodaje listy, = kopiuje liste, ==, !=
class Element{
    friend class List;
    int wartosc;
    class Element *next;
    friend istream &operator >> (istream &s1, class List &o1);
    friend ostream &operator << (ostream &s1, class List &o1);
};
class List{
private:
    friend istream &operator >> (istream &s1, class List &o1);
    friend ostream &operator << (ostream &s1, class List &o1);
    class Element *head;
public:
    List(){
        head = nullptr;
    }
    List(class List &o1){
        if(!o1.head) return;
        auto *n_element = new Element;
        n_element->wartosc = o1.head->wartosc;
        Element *i = o1.head;
        Element *prev = n_element;
        head = n_element;
        i = i->next;
        while(i != nullptr){
            auto *_element = new Element;
            _element->wartosc = i->wartosc;
            prev->next = _element;
            prev = _element;
            i = i->next;
        }
        prev->next = nullptr;
    }
    ~List() {
        while(head != nullptr) {
            class Element *toDelete;
            toDelete = head;
            head = head->next;
            delete toDelete;
        }
    }
    List &operator = (const class List &o1){
        if(!o1.head) return *this;
        auto *n_element = new Element;
        n_element->wartosc = o1.head->wartosc;
        Element *i = o1.head;
        Element *prev = n_element;
        head = n_element;
        i = i->next;
        while(i != nullptr){
            auto *_element = new Element;
            _element->wartosc = i->wartosc;
            prev->next = _element;
            prev = _element;
            i = i->next;
        }
        prev->next = nullptr;
        return *this;
    }
    bool operator == (class List &o1){
        Element *i = this->head;
        Element *j = o1.head;
        if (i == j) return true;
        do{
            if(i->wartosc != j->wartosc) return false;
            i = i->next;
            j = j->next;
        }while(i && j);
        if(!i && !j) return true;
        else return false;
    }

    bool operator != (class List &o1){
        Element *i = this->head;
        Element *j = o1.head;
        if(i == j) return false;
        do{
            if(i->wartosc != j->wartosc) return true;
            i = i->next;
            j = j->next;
        }while(i && j);
        if (!i && !j) return false;
        else return true;
    }
};
istream &operator >> (istream &s1, class List &o1){
    auto *element = new Element;
    s1 >> element->wartosc;
    if(!o1.head) {
        o1.head = element;
        o1.head->next = nullptr;
        return s1;
    }
    Element *n = o1.head;
    while(n->next != nullptr) n = n->next;
    n->next = element;
    element->next = nullptr;
    return s1;
}

ostream &operator << (ostream &s1, class List &o1){
    Element *n = o1.head;
    while(n){
        s1 << n->wartosc << ", " ;
        n = n->next;
    }
    return s1;
}

int main() {
    class List list;
    cin >> list;
    cin >> list;
    cin >> list;
    cout << list << endl;
    class List list2(list), list3;
    cout << list2;
    list3 = list2;
    if(list3 == list2) cout << "WOW\n";
    cin >> list3;
    if(list3 != list2) cout << "WOW2\n";
    cout << list3 << endl;
    cout << list2;
    return 0;
}