//
// Created by Maciej on 24.05.2018.
//

#ifndef MAPTREE_MAP_H
#define MAPTREE_MAP_H

#include <iostream>

template <typename Key, typename Value>
class Map;


template <typename Key, typename Value>
class Element{
public:
    Element<Key,Value>();
    Key first;
    Value second;
private:
    bool checked;
    friend class Map<Key,Value>::Iterator;
    friend class Map<Key,Value>;
    Element<Key,Value> *parent;
    Element<Key,Value> *right;
    Element<Key,Value> *left;
};


template <typename Key, typename Value>
class Map {
public:

    class Iterator;

    Map<Key,Value>();

    ~Map<Key,Value>();

    Value &operator[] (const Key &key);

    Iterator begin();

    Iterator end();

private:
    void delocate(Element<Key,Value> *toDelete);
    Element<Key,Value> *root;
    void clear(Element<Key,Value> *element);
};

template<typename Key, typename Value>
class Map<Key,Value>::Iterator{
public:

    Iterator();

    Iterator (Element<Key,Value> *n);

    Iterator &operator++();

    Iterator operator++(int);

    bool operator != (const Iterator&o1)const;

    bool operator == (const Iterator&o1)const;

    Element<Key,Value> *operator->();

private:
    void clear(Element<Key,Value> *element);
    Element<Key,Value> *next();
    Element<Key,Value> *currentElement;
};


#endif //MAPTREE_MAP_H
