// C++ program to implement a stack using linked lists
 
// Header file for input output functions
#include <iostream>
#include <bits/stdc++.h>
using namespace std;

//Implement node class for linked list stack
class Node{
    public:
        //Make variables data to hold the value of the node and next to point to the next node
        int data;
        Node *next;
};
//Implement stack as a class
class Stack{
    public:
        //create public variables:top to indicate the top of the stack or head of the linked list and tail 
        //to indicate bottom of stack or end of linked list. Both initialized as NULL
        Node *top,*tail;   
        Stack(){
            //constructor initialized whenever an instance of the class is created
            top=NULL;
            tail=NULL;
        }          
int push(int value){
    //Method to push or add elements on top of the stack
    
    Node *newNode=new Node;
    newNode->data=value;
    if (top==NULL){
        //If stack is empty, set both tail and top as the inserted element.
        newNode->next=NULL;
        top=newNode;
        tail=newNode;
    }
    else{
        //Otherwise set the inserted element as the new top and point it to the previous top
        newNode->next=top;
        top=newNode;
    }
    return 0;
}
int pop(){
    //Method to pop or remove element from top of the stack
    //Define top_value to hold the element on top to be returned
    int topValue;
    if(top==NULL){
        //Display "Stack Underflow" and exit if the stack is empty
        cout<<"Stack Underflow!";
        exit(0);
    }
    else{
        //Otherwise store top element as top_value to be returned and point top to the element under
        topValue=top->data;
        top=top->next;
    }
    return topValue;
}
int peep(){   
    //Method to show element at the top of the stack
    //Define top_value to hold the element on top to be returned
    int topValue;
    if(top==NULL){
        //Display "Stack Underflow" and exit if the stack is empty
        cout<<"Stack Underflow!";
        exit(0);
    }
    else{
        //Otherwise store top element as top_value to be returned
        topValue=top->data;
    }
    return topValue;
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