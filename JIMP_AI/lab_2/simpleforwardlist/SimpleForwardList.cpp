
#include "SimpleForwardList.h"


ForwardList *CreateNode(int value){
    auto *element = new ForwardList;
    element->value = value;
    element->next = nullptr;
    return element;
}

void DestroyList(ForwardList *list){
    while(list != nullptr){
        ForwardList *toDelete = list;
        list = list->next;
        delete toDelete;
    }
}


ForwardList *PushFront(ForwardList *list, int value) {
    if (list == nullptr) return nullptr;
    else{
        auto *element = new ForwardList;
        element->value = value;
        element->next = list;
        list = element;
        return list;
    }
}

void Append(ForwardList *list, ForwardList *tail){
    ForwardList *i = list;
    if(!list) list = tail;
    else{
        while(i->next) i= i->next;
        i->next = tail;
    }
}