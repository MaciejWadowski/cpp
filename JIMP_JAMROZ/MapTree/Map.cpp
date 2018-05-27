//
// Created by Maciej on 24.05.2018.
//

#include "Map.h"

template<class Key, class Value>
Element<Key, Value>::Element() {
    left = nullptr;
    right = nullptr;
}

template<class Key, class Value>
Map<Key, Value>::Map() {
    root = nullptr;
}

template<class Key, class Value>
Map<Key, Value>::~Map() {
    delocate(root);
    root = nullptr;
}

template<class Key, class Value>
void Map<Key, Value>::delocate(Element<Key, Value> *toDelete) {
    if(!toDelete)
        return;

    delocate(toDelete->left);
    delocate(toDelete->right);

    delete toDelete;
}

template<class Key, class Value>
Value &Map<Key, Value>::operator[](const Key &key){
    Element<Key,Value> *i = root, *newElement, *j = nullptr;

    while(i){

        if(key == i->first)
            return i->second;

        else if(key < i->first) {
            j = i;
            i = i->left;
        }

        else{
            j = i;
            i = i->right;
        }
    }

    newElement = new Element<Key,Value>;
    newElement->first = key;
    newElement->left = nullptr;
    newElement->right = nullptr;

    if(!root)
        root = newElement;

    else{

        newElement->parent = j;

        if(j->first > key)
            j->left = newElement;

        else
            j->right = newElement;

    }

    return newElement->second;
}

template<class Key, class Value>
typename Map<Key,Value>::Iterator Map<Key, Value>::begin() {
    Element<Key,Value> *n = root;

    while(n->left)
        n = n->left;

    return Iterator{n};
}

template<class Key, class Value>
typename Map<Key,Value>::Iterator Map<Key, Value>::end() {
    return Iterator{nullptr};
}



template<class Key, class Value>
typename Map<Key,Value>::Iterator &Map<Key,Value>::Iterator::operator++() {
    if(currentElement->right){
        currentElement = currentElement->right;

        while(currentElement->left)
            currentElement = currentElement->left;

        return *this;
    }

    Element<Key,Value> *n = currentElement->parent;
    while( n && currentElement == n->right){
        currentElement = n;
        n = n->parent;
    }

    currentElement = n;
    return *this;
}

template<class Key, class Value>
bool Map<Key,Value>::Iterator::operator!=(const Iterator &o1)const {
    return currentElement != o1.currentElement;
}

template<class Key, class Value>
Map<Key,Value>::Iterator::Iterator() {
    currentElement = nullptr;
}

template<class Key, class Value>
Element<Key,Value> *Map<Key,Value>::Iterator::operator->() {
    return currentElement;
}

template<class Key, class Value>
Map<Key,Value>::Iterator::Iterator(Element<Key, Value> *n) {
        currentElement = n;

        if(currentElement)
            currentElement->checked = true;
}

template<class Key, class Value>
typename Map<Key,Value>::Iterator Map<Key, Value>::Iterator::operator++(int) {
    if(currentElement->right){
        currentElement = currentElement->right;

        while(currentElement->left)
            currentElement = currentElement->left;

        return *this;
    }

    Element<Key,Value> *n = currentElement->parent;
    while( n && currentElement == n->right){
        currentElement = n;
        n = n->parent;
    }

    currentElement = n;
    return *this;
}

template<class Key, class Value>
bool Map<Key, Value>::Iterator::operator==(const Iterator &o1) const {
    return currentElement == o1.currentElement;
}

