// C++ program to implement a doubly linked list
 
// Header file for input output functions
#include <iostream>
#include <bits/stdc++.h>
using namespace std;

//Implement class for list nodes
class Node{
    public:
        //Make variables data:to hold the value of the node; next:to point to the next node
        //prev:point to previous node
        int data;
        Node *next,*prev;
};
//Implement class for doubly linked list
class DoublyLinkedList{
    public:
        //nodes head and tail for head and tail of list
        Node *head=NULL, *tail=NULL;
int InsertInFront(int value){
    //Method to insert elements to front of list
    //Create pointer to new node, initialize and update data as the inserted element
    Node *newNode=new Node;
    newNode->data=value;
    if (head==NULL) {
        //If list is empty, set both head and tail to be the new node
        newNode->next=NULL;
        newNode->prev=NULL;
        head=newNode;
        tail=newNode;
    } else{
        //Otherwise, set "next" of "new node" as the current head, set "prev" of current head as the "new node"
        //and make the "new node" the new head
        newNode->next=head;
        head->prev=newNode;
        head=newNode;
    }
    return 0;
}
int InsertAtBack(int value){
    //Method to insert elements to back of list
    //Create pointer to new node, initialize and update data as the inserted element
    Node *newNode=new Node;
    newNode->data=value;
    newNode->next=NULL;
    if(head==NULL){
        //If list is empty, set both head and tail to be the new node
        newNode->prev=NULL;
        head=newNode;
        tail=newNode;
    }
    else{
        //Otherwise, let current tail "next" point to the "new node", "new node" "prev" point to current 
        //tail and make "new node" the new tail
        tail->next=newNode;
        newNode->prev=tail;
        tail=newNode;
    }
    return 0;
}
};
int main(){
    DoublyLinkedList dll;
    dll.InsertInFront(43);
    dll.InsertInFront(23);
    Node *al=dll.tail;
    cout<<al->data;
    return 0;
}