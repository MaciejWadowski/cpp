//
// Created by Maciej on 24.05.2018.
//

#include "Map.h"

template<class Key, class Value>
Element<Key, Value>::Element() {
    left = nullptr;
    right = nullptr;
    checked = false;
}

template<class Key, class Value>
Map<Key, Value>::Map<Key, Value>() {
    root = nullptr;
}

template<class Key, class Value>
Map<Key, Value>::~Map() {
    delocate(root);
    root = nullptr;
}

template<class Key, class Value>
void Map<Key, Value>::delocate(Element *toDelete) {
    if(!toDelete)
        return;

    delocate(toDelete->left);
    delocate(toDelete->right);

    delete toDelete;
}

template<class Key, class Value>
Value &Map<Key, Value>::operator[](const Key &key){
    Element<Key,Value> *i = root, *new_element, *j = nullptr;

    while(i){

        if(key == i->first){
            return i->second;
        }

        else if(key < i->first) {
            j = i;
            i = i->left;
        }

        else{
            j = i;
            i = i->right;
        }
    }

    new_element = new Element<Key,Value>;
    new_element->first = key;
    new_element->left = nullptr;
    new_element->right = nullptr;

    if(!root)
        root = new_element;

    else{
        new_element->parent = j;

        if(j->first > key)
            j->left = new_element;

        else
            j->right = new_element;

    }

    return new_element->second;
}

template<class Key, class Value>
Iterator<Key, Value> Map<Key, Value>::begin() {
    Element<Key,Value> *n = root;

    while(n->left)
        n = n->left;

    return Iterator<Key,Value>{n};
}

template<class Key, class Value>
Iterator<Key, Value> Map<Key, Value>::end() {
    return nullptr;
};

template<class Key, class Value>
Iterator<Key, Value>::Iterator<Key, Value>(Element<Key, Value> *n) {
    it = n;
    it->checked = true;
}

template<class Key, class Value>
Iterator<Key, Value> Iterator<Key, Value>::nextIt() {
    if(it->left && !it->left->checked)
        it->left;

    else if(it->right && !it->right->checked)
        it->right;

    else if(it->parent) {
        it = it->parent;
        nextIt();
    }

    else{
        clear();
        it = nullptr;
    }
}

template<class Key, class Value>
Iterator<Key, Value> &Iterator<Key, Value>::operator++() {
    nextIt();
    return *this;
}

template<class Key, class Value>
bool Iterator<Key, Value>::operator!=(Iterator<Key, Value> &o1) {
    return this->it != o1.it;
}

template<class Key, class Value>
Iterator<Key, Value>::Iterator<Key, Value>() {
    it = nullptr;
}

template<class Key, class Value>
Iterator<Key, Value> *Iterator<Key, Value>::operator->() {
    return it;
}

