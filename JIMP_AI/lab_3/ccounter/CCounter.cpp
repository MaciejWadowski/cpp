//
// Created by maciej on 31.03.18.
//

#include "CCounter.h"

using std::unique_ptr;
using std::string;
using std::make_unique;
using std::pair;
using std::map;

namespace ccounter{

    unique_ptr<Counter> Init(){
        auto counter = make_unique<Counter>();
        return counter;
    }

    void Inc(string key, unique_ptr<Counter> *counter){
        pair <string, int> new_element ={key, 1};
        map <string, int>::iterator it;

        if((*counter)->data.empty()) (*counter)->data.insert(new_element);

        else{
            it = (*counter)->data.find(key);
            if(it != (*counter)->data.end()) it->second++;
            else (*counter)->data.insert(new_element);
        }
    }

    int Counts(const unique_ptr<Counter> &counter, string key){
        map<string, int>::iterator it;
        it = counter->data.find(key);

        if(it != counter->data.end()) return it->second;
        else return 0;
    }

    void SetCountsTo(string key, int value, unique_ptr<Counter> *counter){
        map<string, int>::iterator it;
        it = (*counter)->data.find(key);
        if(it != (*counter)->data.end()) it->second = value;
    }
}