// C++ program to implement a linked list
 
// Header file for input output functions
#include <iostream>
#include <bits/stdc++.h>
using namespace std;

//Implement class for list nodes
class Node{
    public: 
        //Make variables data to hold the value of the node and next to point to the next node
        int data;
        Node *next;
};
//Implement class for doubly linked list
class LinkedList{
    public:
        //nodes head and tail for head and tail of list
        Node *head,*tail;
            LinkedList() {
                //Consrtuctor to initialize head and tail to NULL
                head=NULL;
                tail=NULL;
            }
int InsertInFront(int value){
    //Method to insert elements to front of list
    //Create pointer to new node, initialize and update data as the inserted element
    Node *newNode=new Node;
    newNode->data=value;
    if (head==NULL){
        //If list is empty, set both head and tail to be the new node
        newNode->next=NULL;
        head=newNode;
        tail=newNode;
    }
    else{
        //Otherwise, set "next" of "new node" as the current head and make the "new node" the new head
        newNode->next=head;
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
        head=newNode;
        tail=newNode;
    }
    else {
        //Otherwise, let current tail "next" point to the "new node" and make "new node" the new tail
        tail->next=newNode;
        tail=newNode;
    }
    return 0;
} 
int InsertAtPosition(int pos,int value){
    //Method to insert elements to back of list
    //Create pointer to new node, initialize and update data as the inserted element
    int i;
    Node *prev,*current=head,*newNode=new Node;
    if (pos==1){
        InsertInFront(value);
    }
    else{
        for (i=1;i<pos;i++){
            prev=current;
            current=current->next;
        }
        newNode->data=value;
        newNode->next=current;
        prev->next=newNode;
        if (current==NULL){
            tail=newNode;
        }
    }
    return 0;
} 
int deleteNode(int pos){
    int i=1;
    Node *prev, *current=head;
    if(pos<1){
        cout<<"Invalid Position";
    }
    else if(pos==1){
        head=head->next;
    }
    else{
        while(i<pos && current!=NULL){
            prev=current;
            current=current->next;
            i++;
        }
        if(i==pos){
            prev->next=current->next;
            if(current->next==NULL){
                tail=prev;
            }   
        }
        else{
            cout<<"\nposition is out of range";
        }
    }
    return 0;
} 
int getElement(int pos){
    int element,i;
    Node *current=head;
    if(pos<1){
        cout<<"Invalid Position";
    }
    else{
        for(i=1;i<pos;i++){
            current=current->next;
        }
        if(current==NULL){
            cout<<"Position out of range";
        }
        element=current->data;
    }
    return element;
} 
vector<int> getElements(vector<int> positions){
    vector<int> elements;
    int i,npos=positions.size();
    for(i=0;i<npos;i++){
        elements.push_back(getElement(positions[i]));
    }
    return elements;
}        
};

int main(){
    int a,i;
    vector<int> b={1, 2, 3, 4},c;
    LinkedList ll;
    ll.InsertInFront(10);
    ll.InsertInFront(40);
    ll.InsertInFront(30);
    ll.InsertAtBack(50);
    a=ll.getElement(4);
    cout<<a<<"\n";
    ll.deleteNode(1);
    Node *current=ll.head;
    cout<<current->data;
    ll.InsertInFront(20);
    c=ll.getElements(b);
    for(i=0;i<c.size();i++){
        cout<<c[i]<<" ";
    }
    //cout<<"\n"<< c;
    return 0;
}