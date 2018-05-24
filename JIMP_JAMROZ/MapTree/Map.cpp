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
    Element<Key,Value> *it = root;

    clear(it);

    while(n->left)
        n = n->left;

    return Iterator<Key,Value>{n};
}

template<class Key, class Value>
Iterator<Key, Value> Map<Key, Value>::end() {
    return Iterator<Key,Value>{nullptr};
}




template<class Key, class Value>
Element<Key, Value> * Iterator<Key, Value>::nextIt() {
    if(it->left && !it->left->checked)
        return it->left;

    else if(it->right && !it->right->checked)
        return it->right;

    else if(it->parent && !it->parent->checked){
        return it->parent;
    }

    else if(it->parent){
        it = it->parent;
        return nextIt();
    }
    else{
        clear(it);
        return nullptr;
    }
}

template<class Key, class Value>
Iterator<Key, Value> &Iterator<Key,Value>::operator++() {
    Element<Key,Value> *n = nextIt();
    it = n;
    if(it)
        it->checked = true;
    return *this;
}

template<class Key, class Value>
bool Iterator<Key, Value>::operator!=(const Iterator<Key, Value> &o1) {
    return this->it != o1.it;
}

template<class Key, class Value>
Iterator<Key, Value>::Iterator() {
    it = nullptr;
}

template<class Key, class Value>
Element<Key,Value> *Iterator<Key,Value>::operator->() {
    return it;
}


template<class Key, class Value>
Element<Key, Value> Iterator<Key, Value>::clear(Element<Key, Value> *it) {

    if(it->left && !it->left->checked)
        clear(it->left);

    if(it->right && !it->right->checked)
        clear(it->right);

    if(it)
        it->checked = false;
}

template<class Key, class Value>
Iterator<Key,Value>::Iterator(Element<Key, Value> *n) {
        it = n;
        if(it)
            it->checked = true;
}

template<class Key, class Value>
void Map<Key, Value>::clear(Element<Key, Value> *it) {
    if(!it || it->checked)
        return;

    if(it->left)
        if(!it->left->checked);
            clear(it->left);

    if(it->right)
        if(!it->right->checked)
            clear(it->right);

    if(it)
        it->checked = false;
};