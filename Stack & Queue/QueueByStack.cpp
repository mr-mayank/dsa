#include<bits/stdc++.h>
using namespace std;

class Queue{
    stack<int> s1,s2;
    public:
        void push(int x){
            s1.push(x);
        }
        int pop(){
            if(s1.empty() && s2.empty()){
                return -1;
            }
            if(s2.empty()){
                while(!s1.empty()){
                    s2.push(s1.top());
                    s1.pop();
                }
            }
            int x = s2.top();
            s2.pop();
            return x;
        }
        int size(){
            return s1.size() + s2.size();
        }
        bool empty(){
            return s1.empty() && s2.empty();
        }
};

int main(){
    Queue q;
    q.push(1);
    q.push(2);
    q.push(3);
    q.push(4);
    cout<<q.pop()<<endl;
    cout<<q.pop()<<endl;
    cout<<q.size()<<endl;
    cout<<q.empty()<<endl;
    return 0;
}