#include<bits/stdc++.h>
using namespace std;

struct Node{
    int data;
    Node* next;
};

Node* head;

void Insert(int data){
    Node* temp = new Node();
    temp->data = data;
    temp->next = head;
    head = temp;
}

void Print(){
    Node* temp = head;
    cout<<"List is: ";
    while(temp != NULL){
        cout<<temp->data<<" ";
        temp = temp->next;
    }
    cout<<endl;
}

void LastToFirst(){
    Node* temp = head;
    Node* prev = NULL;
    while(temp->next != NULL){
        prev = temp;
        temp = temp->next;
    }
    prev->next = NULL;
    temp->next = head;
    head = temp;
}

int main(){
    head = NULL;
    Insert(2);
    Insert(4);
    Insert(6);
    Insert(8);
    Print();
    LastToFirst();
    Print();
    return 0;
}
