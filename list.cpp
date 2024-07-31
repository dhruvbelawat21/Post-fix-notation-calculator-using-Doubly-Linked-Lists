
#include "node.h"
#include "list.h"

/* PART B */
/* Stacks using Linked Lists */

/* 
Linked Lists with Sentinels 
[X]<->[7]<->[3]<->[2]<->[X]
The head and tails are dummy elements ([X]) that do not have valid values.
These are called sentinel elements.
*/


    List::List(){
        sentinel_head=new Node(true);
        sentinel_tail=new Node(true);
        sentinel_head->next=sentinel_tail;
        sentinel_tail->prev=sentinel_head;
        size=0;
    }

    List::~List(){
        delete sentinel_head;
        delete sentinel_tail;
    }

    // Insert an element at the tail of the linked list 
    void List::insert(int v){
        Node *newbie=new Node(v,sentinel_tail,sentinel_tail->prev);
        sentinel_tail->prev=newbie;
        newbie->prev->next=newbie;
        size=size+1;

    }

    // Delete the tail of the linked list and return the value
    // You need to delete the valid tail element, not the sentinel
    int List::delete_tail(){
        Node *a;
        a=sentinel_tail->prev;
        sentinel_tail->prev->get_value();
        sentinel_tail->prev->prev->next=sentinel_tail;
        sentinel_tail->prev=sentinel_tail->prev->prev;
        int temp=a->get_value();
        
        delete a;
        size=size-1;
        return temp;
    }

    // Return the size of the linked list 
    // Do not count the sentinel elements
    int List::get_size(){
        return size;
    }

    // Return a pointer to the sentinel head of the linked list 
    Node* List::get_head(){
        return sentinel_head;
    }

