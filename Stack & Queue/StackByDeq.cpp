#include<bits/stdc++.h>
using namespace std;        

class Stack{
    deque<int> deq;
    public:
        void push(int x){
            deq.push_back(x);
        }
        void pop(){
            deq.pop_back();
        }
        int top(){
            return deq.back();
        }
        int size(){
            return deq.size();
        }
        bool empty(){
            return deq.empty();
        }
};

int main(){
    Stack s;
    s.push(1);
    s.push(2);
    s.push(3);
    s.push(4);
    cout<<s.top()<<endl;
    s.pop();
    cout<<s.top()<<endl;
    cout<<s.size()<<endl;
    cout<<s.empty()<<endl;
    return 0;
}