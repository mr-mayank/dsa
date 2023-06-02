#include<bits/stdc++.h>
using namespace std;

struct Node{
    int data;
    Node* next;

    Node(int x){
        data = x;
        next = NULL;
    }
};

Node* head;


bool checkCircular(Node* head){
    Node* temp = head;
    while(temp != NULL){
        if(temp->next == head){
            return true;
        }
        temp = temp->next;
    }
    return false;
}

int main(){
    head = NULL;
    head = new Node(10);
    head->next = new Node(20);
    head->next->next = new Node(30);

    cout<<checkCircular(head)<<endl;
    return 0;
}