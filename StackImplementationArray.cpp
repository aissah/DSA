// C++ program to implement a stack using arrays
 
// Header file for input output functions
#include <iostream>
#include <bits/stdc++.h>
using namespace std;


//stack_height stores the maximum number of elements that can be stored in the stack.
#define stack_height 10
//Implement stack as a class
class Stack{
    public:
        //create public variables:top to indicate index at top of stack, top is initiallized as -1 and
        //set to -1 whenever the stack is empty
        int top,arr[stack_height];   
        Stack(){
            //constructor initialized whenever an instance of the class is created
            top=-1;
        }   
        
int push(int value){
    //Method to push or add elements on top of the stack
    if(top==stack_height-1){
        //Display "Stack Overflow" if the stack is already full
        cout<<"Stack Overflow!";
        exit(0);
    }
    else{
        //Otherwise increase the value of top and put the element in the top position
        top++;
        arr[top]=value;
    }
    return 0;
}
int pop(){
    //Method to pop or remove element from top of the stack
    //Define top_value to hold the element on top to be returned
    int top_value;
    if(top==-1){
        //Display "Stack Underflow" and exit if the stack is empty
        cout<<"Stack Underflow!";
        exit(0);
    }
    else{
        //Otherwise store top element as top_value to be returned and point top to the element under
        top_value=arr[top];
        top--;
    }
    return top_value;
}
int peep(){   
    //Method to show element at the top of the stack
    //Define top_value to hold the element on top to be returned
    int top_value;
    if(top==-1){
        //Display "Stack Underflow" and exit if the stack is empty
        cout<<"Stack Underflow!";
        exit(0);
    }
    else{
        //Otherwise store top element as top_value to be returned
        top_value=arr[top];
    }
    return top_value;
}
};
//Execute an example in Main() function
int main(){
    Stack books;
    int a;
    books.push(5);
    a=books.pop();
    cout<<a;
    books.push(4);
    books.push(6);
    a=books.peep();
    cout<<"\n"<<a;
    books.push(6);
}