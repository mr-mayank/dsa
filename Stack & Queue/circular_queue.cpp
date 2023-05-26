#include<bits/stdc++.h>
using namespace std;

class Queue{
    int rear, front;
    int size;
    int *arr;

    public:
    Queue(int s){
        front = rear = -1;
        size = s;
        arr = new int[s];
    }

    void enqueue(int x);
    int dequeue();
    void display();
    bool isEmpty();
};

void Queue :: enqueue(int x){
    if((front == 0 && rear == size-1) || (rear == (front-1)%(size-1))){
        cout<< "Queue is full" <<endl;
        return;
    }
    else if(front == -1){
        front = rear = 0;
        arr[rear] = x;
    }
    else if(rear == size-1 && front != 0){
        rear = 0;
        arr[rear] = x;
    }
    else{
        rear++;
        arr[rear] = x;
    }
}

int Queue :: dequeue(){
    if(front == -1){
        cout<< "Queue is empty" <<endl;
        return INT_MIN;
    }
    int data = arr[front];
    arr[front] = -1;
    if(front == rear){
        front = rear = -1;
    }
    else if(front == size-1){
        front = 0;
    }
    else{
        front++;
    }
    return data;
}

void Queue :: display(){
    if(front == -1){
        cout<< "Queue is empty" <<endl;
        return;
    }
    cout<< "Elements in Circular Queue are: ";
    if(rear >= front){
        for(int i=front; i<=rear; i++){
            cout<< arr[i] << " ";
        }
    }
    else{
        for(int i=front; i<size; i++){
            cout<< arr[i] << " ";
        }
        for(int i=0; i<=rear; i++){
            cout<< arr[i] << " ";
        }
    }
    cout<<endl;
}

bool Queue :: isEmpty(){
    return (front == -1);
}

int main(){
    Queue q(5);
    q.enqueue(14);
    q.enqueue(22);
    q.enqueue(13);
    q.enqueue(-6);
    q.display();
    cout<< "Deleted value = " << q.dequeue() <<endl;
    cout<< "Deleted value = " << q.dequeue() <<endl;
    q.display();
    q.enqueue(9);
    q.enqueue(20);
    q.enqueue(5);
    q.display();
    q.enqueue(20);
    return 0;
}