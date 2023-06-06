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

//insertion 
Node* push(Node* head, int data){
    Node* temp = new Node(data);
    temp->next = head;
    head = temp;
    return head;
}


Node* push_back_without(Node* head, int x){
    Node* temp = new Node(x);
    if(head == NULL){
        head = temp;
        return head;
    }
    Node* curr = head;
    while(curr->next != NULL){
        curr = curr->next;
    }
    curr->next = temp;
    return head;
}

Node* push_back(Node* &tail, int x){
    Node* temp = new Node(x);
    if(tail == NULL){
        tail = temp;
        return tail;
    }
    tail->next = temp;
    tail = temp;
    return tail;
}
void push_at(Node* &tail,Node* &head, int x, int pos){
    //insert at head
    if(pos == 1){
       push(head, x);
         return;
    }
    //insert at middle
    Node* curr = head;
    Node* temp = new Node(x);
    for(int i=0; i<pos-2; i++){
        curr = curr->next;
    }
    if(curr->next == NULL){
        push_back(tail, x);
        return; 
    }
    temp->next = curr->next;
    curr->next = temp;
}

//deletion
Node* pop(Node* &head){
    if(head == NULL){
        return NULL;
    }
    Node* temp = head;
    head = head->next;
    delete(temp);
    return head;
}


void pop_at(int pos, Node* &head, Node* &tail){
    if(pos == 1){
        pop(head);
        return;
    }
    Node* curr = head;
    for(int i=0; i<pos-2; i++){
        curr = curr->next;
    }
    if(curr->next->next == NULL){
        tail = curr;

    }
    Node* temp = curr->next;
    curr->next = temp->next;
    delete(temp);
    return ;
}

//searching
int search(Node* head, int x){
    Node* curr = head;
    int pos = 1;
    while(curr != NULL){
        if(curr->data == x){
            return pos;
        }
        pos++;
        curr = curr->next;
    }
    return -1;
}



//traversal 
void printList(Node* head){
    Node* temp = head;
    while(temp != NULL){
        cout<<temp->data<<" ";
        temp = temp->next;
    }
}

int main(){
    Node* node1 = NULL;
    node1 = push(node1, 10);
    head = node1;
    tail = node1;
    head = push(head, 20);
    head = push(head, 30);
    tail = push_back(tail, 40);
    tail = push_back(tail, 50);
    push_at(tail,head, 60, 6);

    // head = pop(head);
     pop_at(6, head, tail);
     pop_at(1, head, tail);

    printList(head);

    cout<<endl;
    cout<<head->data<<" "<<tail->data;
     
    return 0; 
}