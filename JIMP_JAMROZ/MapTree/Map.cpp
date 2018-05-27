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
    Element<Key,Value> *i = root, *new_element, *j = nullptr;

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
typename Map<Key,Value>::Iterator Map<Key, Value>::begin() {
    Element<Key,Value> *n = root;
    Element<Key,Value> *it = root;

    clear(it);

    while(n->left)
        n = n->left;

    return Iterator{n};
}

template<class Key, class Value>
typename Map<Key,Value>::Iterator Map<Key, Value>::end() {
    return Iterator{nullptr};
}

template<class Key, class Value>
Element<Key, Value> * Map<Key,Value>::Iterator::nextIt() {
    if(currentElement->left && !currentElement->left->checked)
        return currentElement->left;

    else if(currentElement->right && !currentElement->right->checked)
        return currentElement->right;

    else if(currentElement->parent && !currentElement->parent->checked)
        return currentElement->parent;

    else if(currentElement->parent){
        currentElement = currentElement->parent;
        return nextIt();
    }

    else{
        clear(currentElement);
        return nullptr;
    }
}

template<class Key, class Value>
typename Map<Key,Value>::Iterator &Map<Key,Value>::Iterator::operator++() {
    Element<Key,Value> *n = nextIt();
    currentElement = n;

    if(currentElement)
        currentElement->checked = true;

    return *this;
}

template<class Key, class Value>
bool Map<Key,Value>::Iterator::operator!=(const Iterator &o1) {
    return this->currentElement != o1.currentElement;
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
void Map<Key,Value>::Iterator::clear(Element<Key, Value> *element) {

    if(element->left && !element->left->checked)
        clear(element->left);

    if(element->right && !element->right->checked)
        clear(element->right);

    if(element)
        element->checked = false;
}

template<class Key, class Value>
Map<Key,Value>::Iterator::Iterator(Element<Key, Value> *n) {
        currentElement = n;

        if(currentElement)
            currentElement->checked = true;
}

template<class Key, class Value>
typename Map<Key,Value>::Iterator Map<Key, Value>::Iterator::operator++(int) {
    Element<Key,Value> *n = nextIt();
    currentElement = n;

    if(currentElement)
        currentElement->checked = true;

    return *this;
}

template<class Key, class Value>
void Map<Key, Value>::clear(Element<Key, Value> *element) {
    if(!element || element->checked)
        return;

    if(element->left && !element->left->checked);
            clear(element->left);

    if(element->right && !element->right->checked)
            clear(element->right);

    if(element)
        element->checked = false;
};

