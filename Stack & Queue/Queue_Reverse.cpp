#include<bits/stdc++.h>
using namespace std;

queue<int> reverse(queue<int> q){
    stack<int> s;
    while(!q.empty()){
        s.push(q.front());
        q.pop();
    }
    while(!s.empty()){
        q.push(s.top());
        s.pop();
    }
    return q;
}

int main(){
    queue<int> q;
    q.push(10);
    q.push(20);
    q.push(30);
    q.push(40);
    q = reverse(q);
    while(!q.empty()){
        cout<< q.front() <<" ";
        q.pop();
    }
    cout<< endl;
    return 0;
}