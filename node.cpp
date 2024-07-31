
#include "node.h"
/* PART B */
/* Stacks using Linked Lists */



    // Use to construct a sentinel node (see list.h)
    Node::Node(bool sentinel){
        is_sentinel=true;
    }

    // Use to construct a regular node
    Node::Node(int v, Node* nxt=nullptr, Node* prv=nullptr){
        value=v;
        next=nxt;
        prev=prv;
    }

    // Return whether a node is a sentinel node 
    // Use it to check if we are at the ends of a list
    bool Node::is_sentinel_node(){
        if(next==nullptr || prev==nullptr){
            return true;
        }
        else{
            return false;
        }
    }

    // Return the value of a node
    int Node::get_value(){
        return value;
    }
