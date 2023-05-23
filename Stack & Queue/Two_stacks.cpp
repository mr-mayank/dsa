#include<bits/stdc++.h>
using namespace std;

class TwoStack {
    int *arr;
    int size;
    int top1, top2;

public:

TwoStack(int s){
    this->size = s;
    arr = new int[s];
    top1 = -1;
    top2 = size;
}

void push1(int x){
    if(top1 < top2 - 1){
        top1++;
        arr[top1] = x;
    }
    else{
                exit(-1);
    }   
}

void  push2(int x){
    if(top1 < top2 - 1){
        top2--;
        arr[top2] = x;
    }
    else{
        exit(-1);
    }   
}

int pop1(){
    if(top1 >= 0){
        int x = arr[top1];
        top1--;
        return x;
    }
    else{
        return -1;
    }
}

int pop2(){
    if(top2 < size){
        int x = arr[top2];
        top2++;
        return x;
    }
    else{
        return -1;
    }

}
    
    };

int main(){
    TwoStack s(5);
    s.push1(10);
    s.push2(20);
    s.push1(30);
    s.push2(40);
    s.push1(50);
    s.push2(60);
    cout<<s.pop1()<<endl;
    cout<<s.pop2()<<endl;
    cout<<s.pop1()<<endl;
    cout<<s.pop2()<<endl;
    cout<<s.pop1()<<endl;

}
