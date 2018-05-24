//
// Created by Maciej on 24.05.2018.
//

#ifndef MAPTREE_MAP_H
#define MAPTREE_MAP_H

#include <iostream>

template <typename Key, typename Value>
class Map;
template <typename Key, typename Value>
class Iterator;


template <class Key, class Value>
class Element{
public:
    Element<Key,Value>();
    Key first;
    Value second;
    bool checked;
private:
    friend class Map;
    friend class Iterator;
    Element<Key,Value> *parent;
    Element<Key,Value> *right;
    Element<Key,Value> *left;
};

template<class Key, class Value>
class Iterator{
public:

    Iterator<Key,Value> ();

    Iterator<Key,Value> (Element<Key,Value> *n);

    Iterator<Key,Value> &operator++();

    bool operator != (Iterator<Key,Value> &o1);

    Iterator<Key,Value> *operator->();

private:
    Iterator<Key,Value> nextIt();
    Element<Key,Value> *it;
};

template <class Key, class Value>
class Map {
public:

    Map<Key,Value>();

    ~Map<Key,Value>();

    Value &operator[] (const Key &key);

    Iterator<Key,Value> begin();

    Iterator<Key,Value> end();

    void delocate(Element *toDelete);

private:
    Element *root;
};

#endif //MAPTREE_MAP_H
