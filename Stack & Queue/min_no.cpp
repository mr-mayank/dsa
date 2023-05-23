#include<bits/stdc++.h>
using namespace std;

stact<int> st;

bool isEmpty(stack <int> &s){
    if(s.empty()){
        return true;
    }
    else{
        return false;
    }
}

void isFull(stack <int> &s, int n){
    if(s.size() == n){
        cout<<"true"<<endl;
    }
    else{
        cout<<"false"<<endl;
    }
}

void push(stack <int> &s, int a){
    
    s.push(a);
}


int pop(stack <int> &s){
    if(s.empty()){
        return -1;
    }
    int x = s.top();
    s.pop();
    return x;
}

int getMin(stack <int> &s){
    if(s.empty()){
        return -1;
    }
    int x = s.top();
    s.pop();
    int y = getMin(s);
    s.push(x);
    if(y == -1){
        return x;
    }
    else{
        return min(x,y);
    }
}

int main(){
    int n, a;
    cin>> n;
    while(!isEmpty(s)){
        pop(s);
    }
    while(!isFull(s,n)){
        cin>>a;
        push(s,a);
    }
    cout<<getMin(s)<<endl;
}