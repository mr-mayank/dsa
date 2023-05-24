#include<bits/stdc++.h>
using namespace std;

class SortedStack{
    public:
    stack<int> s;
    void sort();
};

void insert(stack<int> &s, int ele){
    if(s.empty() || ele > s.top()){
        s.push(ele);
        return;
    }
    int topele = s.top();
    s.pop();
    insert(s, ele);
    s.push(topele);
}

void SortedStack :: sort(){
    if(s.empty()){
        return;
    }
    int ele = s.top();
    s.pop();
    sort();
    insert(s, ele);
}


int main(){
    SortedStack s;
    s.s.push(1);
    s.s.push(2);
    s.s.push(3);
    s.s.push(4);
    s.s.push(5);
    s.s.push(6);
    s.s.push(7);
    s.s.push(8);
    s.s.push(9);
    s.s.push(10);
    s.sort();
    while(!s.s.empty()){
        cout<< s.s.top() <<endl;
        s.s.pop();
    }
    return 0;
}