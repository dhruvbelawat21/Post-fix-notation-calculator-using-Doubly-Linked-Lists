
#include <stdexcept>
#include <iostream>
#include "stack_b.h"
using namespace std;
/* PART B */
/* Dynamic Stacks */


    Stack_B::Stack_B(){
        size=0;
        capacity=1024;
        
        try
        {
            stk=new int[capacity];
        }
        
        catch(const bad_alloc &e)
        {
            throw runtime_error("Out of Memory");
        }
    }

    // Destructor
     Stack_B::~Stack_B(){
        delete[] stk;
     }

    void Stack_B::push(int data){
        if(capacity==size){
            int *stk2;
            stk2=new int[2*capacity];
            for(int i=0;i<size;i++){
                stk2[i]=stk[i];

            }
            //redifining stk problem nhi hoga na??
            stk2[size]=data;
            capacity=2*capacity;
            stk=new int[capacity];
            for (int i=0;i<=size;i++) {
                stk[i]=stk2[i];
        }
            delete[] stk2;
            size=size+1;
        }
        else{
            stk[size]=data;
            size=size+1;
        }

    }

    int Stack_B::pop(){
        if(size==0){
            const std::string message="Empty Stack";
            throw std::runtime_error(message);
    }
        int b= stk[size-1];
        stk[size-1]=0;
        size=size-1;

        if(size<capacity/2 && capacity>=2048){
            int *stk3;
            stk3=new int[capacity/2];
            for(int i=0;i<size;i++){
                stk3[i]=stk[i];

            }
                capacity=capacity/2;
                stk=new int[capacity];
                for (int i=0;i<=size;i++) {
                stk[i]=stk3[i];
            }
                delete[] stk3;

    }
    return b;

    }

    int Stack_B::get_element_from_top(int idx){
        if(idx>=size){
            const std::string message="Index out of range";
            throw std::runtime_error(message);
        }
        return stk[size-idx-1];
    }

    int Stack_B::get_element_from_bottom(int idx){
        if(idx>=size){
            const std::string message="Index out of range";
            throw std::runtime_error(message);
        }
        return stk[idx];
    }

    void Stack_B::print_stack(bool top_or_bottom){
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

    int Stack_B::add(){
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
    int Stack_B::subtract(){
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
    int Stack_B::multiply(){
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
    int Stack_B::divide(){
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
    

    int* Stack_B::get_stack(){
        return stk;
    } // Get a pointer to the array

    int Stack_B::get_size(){
        return size;
    } // Get the size of the stack


