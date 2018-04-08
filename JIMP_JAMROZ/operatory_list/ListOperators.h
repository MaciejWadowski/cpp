//
// Created by Maciej on 08.04.2018.
//

#ifndef OPERATORY_LIST_LISTOPERATORS_H
#define OPERATORY_LIST_LISTOPERATORS_H
#include <iostream>
using namespace std;

class Element{
    friend class List;
    int data;
    class Element *next;
    friend istream &operator >> (istream &s1, class List &o1);
    friend ostream &operator << (ostream &s1, class List &o1);
};

class List{
public:
    List(){ head = nullptr; }
    List(const class List &o1);
    ~List();
    List &operator = (const class List &o1);
    List operator + (const class List &o1);
    bool operator==(class List &o1);
    bool operator != (class List &o1);
private:
    friend istream &operator >> (istream &s1, class List &o1);
    friend ostream &operator << (ostream &s1, class List &o1);
    class Element *head;
};



#endif //OPERATORY_LIST_LISTOPERATORS_H
