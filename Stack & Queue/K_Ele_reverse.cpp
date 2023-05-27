#include<bits/stdc++.h>
using namespace std;

queue<int> reverse(queue<int> q,int k){
    stack<int> s;
    queue<int> q1;
    int i=0;
    while(i<k){
        s.push(q.front());
        q.pop();
        i++;
    }
    while(!s.empty()){
        q1.push(s.top());
        s.pop();
    }
    while(!q.empty()){
        q1.push(q.front());
        q.pop();
    }
    return q1;
}

int main(){
    queue<int> q;
    q.push(10);
    q.push(20);
    q.push(30);
    q.push(40);
    q = reverse(q,3);
    while(!q.empty()){
        cout<< q.front() <<" ";
        q.pop();
    }
    cout<< endl;
    return 0;
}