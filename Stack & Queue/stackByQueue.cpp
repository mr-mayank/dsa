#include<bits/stdc++.h>
using namespace std;

class Stack{
    public:
    queue<int> q1, q2;
    int curr_size;
    Stack(){
        curr_size = 0;
    }
    void push(int x);
    int pop();
    int top();
    int size();
};

void Stack :: push(int x){
    curr_size++;
    q2.push(x);
    while(!q1.empty()){
        q2.push(q1.front());
        q1.pop();
    }
    queue<int> q = q1;
    q1 = q2;
    q2 = q;
}

int Stack :: pop(){
    if(q1.empty()){
        return -1;
    }
    int x = q1.front();
    q1.pop();
    curr_size--;
    return x;
}


int Stack :: top(){
    if(q1.empty()){
        return -1;
    }
    return q1.front();
}

int Stack :: size(){
    return curr_size;
}


int main(){
    Stack s;
    s.push(1);
    s.push(2);
    s.push(3);
    s.push(4);
    cout<< s.top() <<endl;
    s.pop();
    cout<< s.top() <<endl;
    s.pop();
    cout<< s.top() <<endl;

    return 0;
}