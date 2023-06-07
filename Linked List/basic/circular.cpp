#include<bits/stdc++.h>
using namespace std;

struct Node{
    int data;
    struct Node* next;

    Node(int x){
        data = x;
        next = NULL;
    }
};

Node* head = NULL;
Node* tail = NULL;

void push(Node* &head, Node* &tail, int x){
    Node* temp = new Node(x);
    if(head == NULL){
        temp->next = temp;
        head = temp;
        tail = temp;
        return;
    }
    tail->next = temp;
    temp->next = head;
    head = temp;
    return;
}

void push_back(Node* &head, Node* &tail, int x){
    Node* temp = new Node(x);
    if(head == NULL){
        temp->next = temp;
        head = temp;
        tail = temp;
        return;
    }
    tail->next = temp;
    temp->next = head;
    tail = temp;
}

void push_at(Node* &head, Node* &tail, int x, int pos){

    if(pos == 1){
       push(head, tail,x);
         return;
    }
    
    Node* temp = new Node(x);
    Node* curr = head;

    while ( pos != 2 ){
        curr = curr -> next;
        pos--;
    }
    if(curr->next == head){
        push_back(head,tail,x);
        return;
    }
    temp->next = curr->next;
    curr->next = temp;

}

void pop(Node* &head, Node* &tail){
    Node* temp = head;
    tail->next = temp->next;
    head = temp-> next;
    delete(temp);
}

void pop_back(Node* &head, Node* &tail){
    Node* temp = head;
    while(temp->next != tail){
        temp = temp->next;
    }
    temp->next = head;
    delete(tail);
    tail = temp;
}

void pop_at(Node* &head, Node* &tail, int pos){

    if(pos == 1){
        pop(head,tail);
        return;
    }

    Node* temp = head;
    Node* curr = head;

    while ( pos != 2 ){
        curr = curr -> next;
        pos--;
    }
    if(curr->next == head){
        pop_back(head,tail);
        return;
    }
    temp = curr->next;
    curr->next = temp->next;
    delete(temp);
    return;
}

void print(Node* head, Node* tail){

    Node* temp = head;

    while (temp != tail){
        cout<<temp->data<<" ";
        temp = temp->next;
    }
    cout<<temp->data<<endl;
    return;
}

int main(){

    Node* node1 = NULL;
    head = node1;
    tail = node1;

    push(head, tail , 10);
    push(head, tail , 20);
    push(head, tail , 30);
    push_back(head, tail , 40);

    push_at(head, tail , 7,5);
    // pop_back(head,tail);
    print(head,tail);
    cout<<head->data<<" "<<tail->data;

    return 0;
}