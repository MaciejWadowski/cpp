//
// Created by Maciej on 08.04.2018.
//

#include "ListOperators.h"

List::List(const class List &o1) {
    if(!o1.head) return;
    auto *n_element = new Element;
    n_element->data = o1.head->data;
    Element *i = o1.head;
    Element *prev = n_element;
    head = n_element;
    i = i->next;
    while(i != nullptr){
        auto *_element = new Element;
        _element->data = i->data;
        prev->next = _element;
        prev = _element;
        i = i->next;
    }
    prev->next = nullptr;
}

List::~List() {
    while(head != nullptr) {
        class Element *toDelete;
        toDelete = head;
        head = head->next;
        delete toDelete;
    }
    head = nullptr;
}

List &List::operator = (const class List &o1){
    if(o1.head == this->head) return *this;
    if((&o1 == nullptr && this == nullptr)||(o1.head == nullptr && this->head == nullptr))return *this;
    if(o1.head == nullptr || &o1 == nullptr) {
        this->~List();
        return *this;
    }
    if(this->head != nullptr) this->~List();
    auto *n_element = new Element;
    n_element->data = o1.head->data;
    Element *i = o1.head;
    Element *prev = n_element;
    this->head = n_element;
    i = i->next;
    while(i != nullptr){
        auto *_element = new Element;
        _element->data = i->data;
        prev->next = _element;
        prev = _element;
        i = i->next;
    }
    prev->next = nullptr;
    return *this;
}

List List::operator+(const class List &o1){
    if(this->head == nullptr && o1.head == nullptr) return *this;
    if(this->head != nullptr && o1.head == nullptr){
        List new_list(*this);
        return new_list;
    }
    if(this->head == nullptr && o1.head != nullptr){
        List new_list(o1);
        return new_list;
    }
    else {
        List new_list(*this);
        Element *i = new_list.head;
        while (i->next) i = i->next;
        Element *j = o1.head;
        auto *prev = new Element;
        prev->data = o1.head->data;
        i->next = prev;
        j = j->next;
        while (j) {
            auto *new_el = new Element;
            new_el->data = j->data;
            prev->next = new_el;
            prev = new_el;
            j = j->next;
        }
        prev->next = nullptr;
        return new_list;
    }
}

bool List::operator==(class List &o1) {
    if((this->head == nullptr && o1.head != nullptr) || (this->head != nullptr && o1.head == nullptr)) return false;
    Element *i = this->head;
    Element *j = o1.head;
    if (i == j) return true;
    do{
        if(i->data != j->data) return false;
        i = i->next;
        j = j->next;
    }while(i && j);

    return (!i &&!j);
}

bool List::operator != (class List &o1){
    if((this->head == nullptr && o1.head != nullptr) || (this->head != nullptr && o1.head == nullptr)) return true;
    Element *i = this->head;
    Element *j = o1.head;
    if(i == j) return false;
    do{
        if(i->data != j->data) return true;
        i = i->next;
        j = j->next;
    }while(i && j);

    return !(!i && !j);
}

istream &operator >> (istream &s1, class List &o1){
    auto *element = new Element;
    s1 >> element->data;
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
        s1 << n->data << ", " ;
        n = n->next;
    }
    return s1;
}