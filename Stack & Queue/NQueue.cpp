#include<bits/stdc++.h>
using namespace std;

class NQueue{
   public:
   int *arr;
   int *front, *rear, *next;
   int n,k;
    int free;
    NQueue(int n, int k){
        this->n = n;
        this->k = k;
        arr = new int[n];
        front = new int[k];
        rear = new int[k];
        next = new int[n];
        for(int i=0; i<k; i++){
            front[i] = rear[i] = -1;
        }
        free = 0;
        for(int i=0; i<n-1; i++){
            next[i] = i+1;
        }
        next[n-1] = -1;
    }
    bool isFull(){
        return (free == -1);
    }
    bool isEmpty(int qn){
        return (front[qn] == -1);
    }
    void enqueue(int item, int qn){
        if(isFull()){
            cout<< "Queue Overflow" <<endl;
            return;
        }
        int i = free;
        free = next[i];
        if(isEmpty(qn)){
            front[qn] = rear[qn] = i;
        }
        else{
            next[rear[qn]] = i;
            rear[qn] = i;
        }
        next[i] = -1;
        arr[i] = item;
    }
    int dequeue(int qn){
        if(isEmpty(qn)){
            cout<< "Queue Underflow" <<endl;
            return INT_MAX;
        }
        int i = front[qn];
        front[qn] = next[i];
        next[i] = free;
        free = i;
        return arr[i];
    }
};


int main(){
    int k = 3, n = 10;
    NQueue q(n, k);

    q.enqueue(15, 2);
    q.enqueue(45, 2);

    q.enqueue(17, 1);
    q.enqueue(49, 1);
    q.enqueue(39, 1);

    q.enqueue(11, 0);
    q.enqueue(9, 0);
    q.enqueue(7, 0);

    cout << "Dequeued element from queue 2 is " << q.dequeue(2) << endl;
    cout << "Dequeued element from queue 1 is " << q.dequeue(1) << endl;
    cout << "Dequeued element from queue 0 is " << q.dequeue(0) << endl;

    return 0;
}


