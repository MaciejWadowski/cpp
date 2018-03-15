//
// Created by maciej on 15.03.18.
//
#include "SimpleForwardList.h"

int main(){
    ForwardList *head;
    ForwardList *new_node;
    head = CreateNode(10);
    head = PushFront(head, 20);
    Append(head,new_node);
    DestroyList(head);
    return 0;
}
