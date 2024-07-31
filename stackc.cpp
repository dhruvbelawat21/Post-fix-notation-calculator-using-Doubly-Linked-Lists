
#include <iostream>
#include <stdexcept>
#include "stack_c.h"
#include "list.h"
using namespace std;
/* PART B */
/* Stacks using Linked Lists */


    Stack_C::Stack_C(){
        try
        {
            stk = new List();
        }
        catch(const bad_alloc &e)
        {
            const std::string message="Out of Memory";
            throw std::runtime_error(message);
        }
        
        
        
    }

    // Destructor
    Stack_C::~Stack_C(){
        delete[] stk;
    }

    void Stack_C::push(int data){
        stk->insert(data);
    }

    int Stack_C::pop(){
        if(stk->get_size()==0){
            const std::string message="Empty Stack";
            throw std::runtime_error(message);
    }
        int temp=stk->delete_tail();
        return temp;
    }

    int Stack_C::get_element_from_top(int idx){
        if(idx>=stk->get_size()){
            const std::string message="Index out of range";
            throw std::runtime_error(message);
        }
        Node *bassi;
        bassi=stk->get_head();

        for(int i=0;i<=stk->get_size()- idx- 1;i++){
            bassi=bassi->next;

        }
        int temp=bassi->get_value();
        return temp;
    }

    int Stack_C::get_element_from_bottom(int idx){
        if(idx>=stk->get_size()){
            const std::string message="Index out of range";
            throw std::runtime_error(message);
        }
        Node* bassi;
        bassi=stk->get_head();

        for(int i=0;i<=idx;i++){
            bassi=bassi->next;

        }
        int temp=bassi->get_value();
        return temp;
    }

    void Stack_C::print_stack(bool top_or_bottom){
        if (!top_or_bottom){
            Node* bassi;
            bassi=stk->get_head();
            for(int i=0;i<stk->get_size()-1;i++){
                bassi=bassi->next;
                cout<<bassi->get_value()<<endl;
            }
            bassi=bassi->next;
            cout<<bassi->get_value();
        }
        else{
            Node *bassi;
            bassi=stk->get_head();
            for(int i=0;i<stk->get_size();i++){
                bassi=bassi->next;
                // cout<<bassi->value<<endl;
            }
            bassi=bassi->next;
            for(int i=0;i<stk->get_size()-1;i++){
                bassi=bassi->prev;
                cout<<bassi->get_value()<<endl;
            }
            bassi=bassi->prev;
            cout<<bassi->get_value();
        }
    }

    int Stack_C::add(){
        if (stk->get_size()<2){
            const std::string message="Not Enough Arguments";
            throw std::runtime_error(message);
        }
        
        int b=stk->delete_tail();
        int c=stk->delete_tail();
        int d=b+c;
        
        stk->insert(d);
        return d;
    }

    int Stack_C::subtract(){
        if (stk->get_size()<2){
            const std::string message="Not Enough Arguments";
            throw std::runtime_error(message);
        }
        int b=stk->delete_tail();
        int c=stk->delete_tail();
        int d=c-b;
        
        stk->insert(d);
        return d;
    }

    int Stack_C::multiply(){
        if (stk->get_size()<2){
            const std::string message="Not Enough Arguments";
            throw std::runtime_error(message);
        }
        int b=stk->delete_tail();
        int c=stk->delete_tail();
        int d=b*c;
        
        stk->insert(d);
        return d;
    }

    int Stack_C::divide(){
        if (stk->get_size()<2){
            const std::string message="Not Enough Arguments";
            throw std::runtime_error(message);
        }
        int b=stk->delete_tail();
        int c=stk->delete_tail();
        if (b==0){
            const std::string message="Divide by Zero Error";
            throw std::runtime_error(message);
        }

        int d = c / b; 
        if ((c < 0 && b > 0) || (c > 0 && b < 0) && (c % b != 0)) {
            d=d-1;
        }
        

        stk->insert(d);
        return d;
    }

    List* Stack_C::get_stack(){
        return stk;
    } // Get a pointer to the linked list representing the stack

    int Stack_C::get_size(){
        
        int temp=stk->get_size();
        return temp;
    } // Get the size of the s
