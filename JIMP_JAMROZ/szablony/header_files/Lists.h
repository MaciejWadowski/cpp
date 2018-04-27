//
// Created by Maciej on 09.04.2018.
//

#ifndef SZABLONY_LISTS_H
#define SZABLONY_LISTS_H

#include <iostream>
using namespace std;

template <typename L>
class List;

template <class L>
class Element{
private:
    friend class List<L>;
    L data;
    class Element<L> *next;
    template <typename U>
    friend istream &operator >> (istream &s1, class List<U> &o1);
    template <typename U>
    friend ostream &operator << (ostream &s1, class List<U> &o1);
};

template <class L>
class List{
public:
    List<L>(){ head = nullptr; }
    List<L>(const class List<L> &o1);
    ~List<L>();
    List<L> &operator = (const class List<L> &o1);
    List<L> operator + (const class List<L> &o1);
    bool operator==(class List<L> &o1);
    bool operator != (class List<L> &o1);
    template <typename U>
    friend istream &operator >> (istream &s1, class List<U> &o1);
    template <typename U>
    friend ostream &operator << (ostream &s1, class List<U> &o1);
private:
    class Element<L> *head;
};

#endif //SZABLONY_LISTS_H
