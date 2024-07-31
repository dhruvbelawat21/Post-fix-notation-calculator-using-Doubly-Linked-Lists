
#include <iostream>
#include <stdexcept>
#include "stack_a.h"
using namespace std;




Stack_A::Stack_A(){
        size=0;

    }

    void Stack_A::push(int data){
        stk[size]=data;
        size=size+1;
    if(size==1024){
            const std::string message="Stack Full";
            throw std::runtime_error(message);
    }
    }

    int Stack_A::pop(){
        if(size==0){
            const std::string message="Empty Stack";
            throw std::runtime_error(message);
    }
        int b=stk[size-1];
        stk[size-1]=0;
        size=size-1;
        return b;
        

    }

    int Stack_A::get_element_from_top(int idx){
        if(idx>=size){
            const std::string message="Index out of range";
            throw std::runtime_error(message);
        }
        return stk[size-idx-1];
    }

    int Stack_A::get_element_from_bottom(int idx){
        if(idx>=size){
            const std::string message="Index out of range";
            throw std::runtime_error(message);
        }
        return stk[idx];
    }

    void Stack_A::print_stack(bool top_or_bottom){
        if (top_or_bottom==true){
            for(int i=0;i<size;i++){
                cout<<stk[size-i-1]<<endl;
            }
        }
        else{
            for(int i=0;i<size;i++){
                cout<<stk[i]<<endl;
            }
        }

    }

    int Stack_A::add(){
        if (size<2){
            const std::string message="Not Enough Arguments";
            throw std::runtime_error(message);
        }
        int b=pop();
        int c=pop();
        int d=b+c;
        
        push(d);
        return d;

    }

    int Stack_A::subtract(){
        if (size<2){
            const std::string message="Not Enough Arguments";
            throw std::runtime_error(message);
        }
        int b=pop();
        int c=pop();
        int d=c-b;
        
        push(d);
        return d;
    }

    int Stack_A::multiply(){
        if (size<2){
            const std::string message="Not Enough Arguments";
            throw std::runtime_error(message);
        }
        int b=pop();
        int c=pop();
        int d=b*c;
        
        push(d);
        return d;
    }

    int Stack_A::divide(){
        if (size<2){
            const std::string message="Not Enough Arguments";
            throw std::runtime_error(message);
        }
        int b = pop();
        int c = pop();
        if (b == 0) {
            const std::string message = "Divide by Zero Error";
            throw std::runtime_error(message);
        }
        
        int d = c / b; 
        if ((c < 0 && b > 0) || (c > 0 && b < 0) && (c % b != 0)) {
            d=d-1;
        }
        
        push(d);
        return d;
    }

    int* Stack_A::get_stack(){
        int *p=stk;
        return p;
    }

    int Stack_A::get_size(){
        return size;
    } // Get the size of the stack


