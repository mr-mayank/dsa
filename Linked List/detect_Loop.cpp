#include<bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    Node* next;
    Node(int data)
    {
        this->data = data;
        next = NULL;
    }
};

bool detectLoop(Node* head){
    if(head==NULL || head->next==NULL){
        return false;
    }
    map<Node*, bool> m;
    Node* temp = head;
    while(temp!=NULL){
        if(m[temp]==true){
            return true;
        }
        m[temp] = true;
        temp = temp->next;
    }
    return false;
}

int main(){
    Node* head = new Node(10);
    Node* temp1 = new Node(20);
    Node* temp2 = new Node(30);
    Node* temp3 = new Node(40);
    Node* temp4 = new Node(50);
    Node* temp5 = new Node(60);
    Node* temp6 = new Node(70);
    
    head->next = temp1;
    temp1->next = temp2;
    temp2->next = temp3;
    temp3->next = temp4;
    temp4->next = temp5;
    temp5->next = temp6;
    temp6->next = NULL;

    cout<<detectLoop(head);
    return 0;
}