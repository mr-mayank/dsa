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

Node* merge(Node* first, Node* second){
    Node* head = NULL;
    Node* tail = NULL;
    if(first->data <= second->data){
        head = first;
        tail = first;
        first = first->next;
    }
    else{
        head = second;
        tail = second;
        second = second->next;
    }
    while(first != NULL && second != NULL){
        if(first->data <= second->data){
            tail->next = first;
            tail = first;
            first = first->next;
        }
        else{
            tail->next = second;
            tail = second;
            second = second->next;
        }
    }
    if(first == NULL){
        tail->next = second;
    }
    else{
        tail->next = first;
    }
    return head;
}

Node* mergeSort(Node* head){
    if(head == NULL || head->next == NULL){
        return head;
    }
    Node* slow = head;
    Node* fast = head->next;
    while(fast != NULL && fast->next != NULL){
        slow = slow->next;
        fast = fast->next;
        if(fast != NULL){
            fast = fast->next;
        }
    }
    Node* second = slow->next;
    slow->next = NULL;
    Node* first = mergeSort(head);
    second = mergeSort(second);
    return merge(first, second);
}

void printList(Node* head){
    Node* temp = head;
    while(temp != NULL){
        cout<<temp->data<<" ";
        temp = temp->next;
    }
}

void Insert(int data){
    Node* temp = new Node(data);
    temp->next = head;
    head = temp;
}

int main(){
    head = NULL;
    Insert(1);
    Insert(2);
    Insert(5);
    Insert(3);
    Insert(6);
    printList(head);
    cout<<endl;
    head = mergeSort(head);
    printList(head);
    return 0;
}