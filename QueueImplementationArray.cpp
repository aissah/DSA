// C++ program to implement a queue using arrays
 
// Header file for input output functions
#include <iostream>
#include <bits/stdc++.h>
using namespace std;

//Indicate maximum length of queue
#define maxQueueLength 10
//Implement Queue as a class
class Queue{
    public:
        //variables front:store index of first element in queue; back:store index of last element in queue;
        //Both front and back are initialized as -1 and set to -1 when queue is empty
        //queueLength: stores the length of the queue; arr; contains elements in the queue
        int front,back,queueLength=0,arr[maxQueueLength];
        Queue(){
            //Consrtuctor to initialize front and back to 0
            front=back=-1; 
        }
int enqueue(int value){
    //Method to add element to back of queue
    if (back==maxQueueLength){
        //Display "Stack Overflow" and exit if the stack is empty
        cout<<"\nQueue Overflow";
    }
    else if (back==-1 || front>back)
    {
        //or if the stack is empty set element to be both the front and back. Update length of queue
        front=back=0;
        arr[back]=value;
        queueLength++;
    }
    else{
        //Otherwise, increase the index of back of the line and insert element there. Update length of queue
        back++;
        arr[back]=value;
        queueLength++;
    }
    return 0;
}
int dequeue(){
    //Method to return and remove element from front of queue
    int i,firstInQueue;
    if (back==-1 || front>back){
        //Display "Stack Underflow" and exit if the stack is empty
        cout<<"\nQueue Underflow";
    }
    else{
        //Otherwise, store front element in firstInQueue to return and update front to point to the next 
        //element in the queue
        //firstInQueue=arr[front];
        //front++;
        //This means the capacity of the array holding the queue reduces with each dequeue
        //Alternatively we can keep front at 0 and shift all elements back by one and update back as such. 
        //This looks like a case of storage against computational power/speed
        firstInQueue=arr[0];
        for(i=0;i<back;i++){
            arr[i]=arr[i+1];
        }
        back--;
        //Update length of queue
        queueLength--;
    }
    return firstInQueue;
}
};


//Execute an example in Main() function
int main(){
    Queue DMVLine;
    int a;
    DMVLine.enqueue(5);
    a=DMVLine.dequeue();
    cout<<a;
    DMVLine.enqueue(4);
    DMVLine.enqueue(6);
    a=DMVLine.dequeue();
    cout<<"\n"<<a;
    DMVLine.enqueue(6);
    a=DMVLine.queueLength;
    cout<<"\n"<<a;
}
