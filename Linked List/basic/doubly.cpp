#include<bits/stdc++.h>
using namespace std;

struct Node{
    int data;
    struct Node* next;
    struct Node* prev;

    Node(int x){
        data = x;
        next = NULL;
        prev = NULL;
    }
};

Node* head = NULL;
Node* tail = NULL;

//traversal 

void print(Node* head){
    Node* temp = head;

    while(temp != NULL){
        cout<<temp->data<<" ";
        temp = temp->next;
    }
    cout<<endl;
}

//length 
int length(Node* head){
    Node* temp = head;
    int count = 0;

    while(temp != NULL){
        count++;
        temp = temp->next;
    }
    return count;
}

//insertion
void push(Node* &head, int x){
    if(head == NULL){
        Node* temp = new Node(x);
        head = temp;
        tail = temp;
        return;
    }
    Node* temp = new Node(x);
    temp -> next = head;
    temp -> prev = NULL;
    head -> prev = temp;
    head = temp;
}

void push_back(Node* &tail,int x){
    if(tail == NULL){
        Node* temp = new Node(x);
        head = temp;
        tail = temp;
        return;
    }
    Node* temp = new Node(x);
    temp->prev = tail;
    tail->next = temp;
    tail = temp;
}

void push_at(Node* &head, Node* &tail, int x, int pos){
    //insert at head
    if(pos == 1){
        push(head, x);
        return;
    }

    Node* curr = head;
    Node* temp = new Node(x);
    while(pos != 1){
        curr = curr->next;
        pos--;
    }
    if(curr->next == NULL){
        push_back(tail, x);
        return;
    }
    temp->prev = curr;
    temp->next = curr->next;
    curr->next->prev = temp;
    curr->next = temp;

}

//seraching
bool search(Node* head, int x){
    Node* temp = head;

    while(temp != NULL){
        if(temp->data == x){
            return true;
        }
        temp = temp->next;
    }
    return false;
}

//deletion
void pop(Node* &head){
    Node* temp = head;
    head = head->next;
    head->prev = NULL;
    delete(temp);
}

void pop_back(Node* &tail){
    Node* temp = tail;
    tail = tail->prev;
    tail->next = NULL;
    delete(temp);
}

void pop_at(Node* &head, Node* &tail, int pos){
    if(pos == 1){
        pop(head);
        return;
    }
    Node* curr = head;
    while(pos != 1){
        curr = curr->next;
        pos--;
    }
    if(curr->next == NULL){
        pop_back(tail);
        return;
    }
    Node* temp = curr;
    temp->prev->next = temp->next;
    temp->next->prev = temp->prev;
    delete(temp);
}

int main(){

    Node* node1 = new Node(10);
    head = node1;
    tail = node1;

    push(head, 20);
    push(head, 30);

    push_back(tail, 40);

    push_at(head, tail, 50, 3);

    print(head);

    pop(head);


    cout<<head->data<<" "<<tail->data<<endl;

    return 0;

}