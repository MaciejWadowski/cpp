//
// Created by Maciej on 09.04.2018.
//

#include "../header_files/Lists.h"


template <class L>
List<L>::List(const class List<L> &o1) {
    if(!o1.head) {
        head = nullptr;
        return;
    }
    Element<L> *n_element = new Element<L>;
    n_element->data = o1.head->data;
    Element<L> *i = o1.head;
    Element<L> *prev = n_element;
    head = n_element;
    i = i->next;
    while(i != nullptr){
        Element<L> *_element = new Element<L>;
        _element->data = i->data;
        prev->next = _element;
        prev = _element;
        i = i->next;
    }
    prev->next = nullptr;
}
template <class L>
List<L>::~List() {
    while(head != nullptr) {
        class Element<L> *toDelete;
        toDelete = head;
        head = head->next;
        delete toDelete;
    }
}

template <class L>
List<L> &List<L>::operator = (const class List<L> &o1){
    if(&o1 == this) return *this;
    if(o1.head == nullptr && this->head == nullptr)return *this;
    if(o1.head == nullptr) {
        this->~List();
        return *this;
    }
    if(this->head != nullptr) this->~List();
    Element<L> *n_element = new Element<L>;
    n_element->data = o1.head->data;
    Element<L> *i = o1.head;
    Element<L> *prev = n_element;
    this->head = n_element;
    i = i->next;
    while(i != nullptr){
        Element<L> *_element = new Element<L>;
        _element->data = i->data;
        prev->next = _element;
        prev = _element;
        i = i->next;
    }
    prev->next = nullptr;
    return *this;
}

template <class L>
List<L> List<L>::operator+(const class List<L> &o1){
    if(this->head == nullptr && o1.head == nullptr) return *this;
    if(this->head != nullptr && o1.head == nullptr){
        List<L> new_list(*this);
        return new_list;
    }
    if(this->head == nullptr && o1.head != nullptr){
        List<L> new_list(o1);
        return new_list;
    }
    else {
        List<L> new_list(*this);
        Element<L> *i = new_list.head;
        while (i->next) i = i->next;
        Element<L> *j = o1.head;
        Element<L> *prev = new Element<L>;
        prev->data = o1.head->data;
        i->next = prev;
        j = j->next;
        while (j) {
            Element<L> *new_el = new Element<L>;
            new_el->data = j->data;
            prev->next = new_el;
            prev = new_el;
            j = j->next;
        }
        prev->next = nullptr;
        return new_list;
    }
}

template <class L>
bool List<L>::operator==(class List<L> &o1) {
    if((this->head == nullptr && o1.head != nullptr) || (this->head != nullptr && o1.head == nullptr)) return false;
    Element<L> *i = this->head;
    Element<L> *j = o1.head;
    if (i == j) return true;
    do{
        if(i->data != j->data) return false;
        i = i->next;
        j = j->next;
    }while(i && j);

    return (!i &&!j);
}

template <class L>
bool List<L>::operator != (class List<L> &o1){
    if((this->head == nullptr && o1.head != nullptr) || (this->head != nullptr && o1.head == nullptr)) return true;
    Element<L> *i = this->head;
    Element<L> *j = o1.head;
    if(i == j) return false;
    do{
        if(i->data != j->data) return true;
        i = i->next;
        j = j->next;
    }while(i && j);

    return !(!i && !j);
}

template <typename U>
istream &operator >> (istream &s1, class List<U> &o1){
    Element<U> *element = new Element<U>;
    s1 >> element->data;
    if(!o1.head) {
        o1.head = element;
        o1.head->next = nullptr;
        return s1;
    }
    Element<U> *n = o1.head;
    while(n->next != nullptr) n = n->next;
    n->next = element;
    element->next = nullptr;
    return s1;
}

template <typename U>
ostream &operator << (ostream &s1, class List<U> &o1){
    Element<U> *n = o1.head;
    while(n){
        s1 << n->data << "\n" ;
        n = n->next;
    }
    return s1;
}