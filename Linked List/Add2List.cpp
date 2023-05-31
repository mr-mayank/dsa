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

struct Node* buildList(int s){
    int x;
    cin>>x;
    Node* head = new Node(x);
    Node* tail = head;
    for(int i=0;i<s-1;i++){
        cin>>x;
        tail->next = new Node(x);
        tail = tail->next;
    }
    return head;
}

void printList(Node* head){
    Node* temp = head;
    while(temp != NULL){
        cout<<temp->data<<" ";
        temp = temp->next;
    }
}

Node* addTwoLists(Node* first, Node* second){
   // sum from left side of list to right side

    // reverse both lists
    Node* prev = NULL;
    Node* curr = first;
    Node* next = NULL;
    while(curr != NULL){
        next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
    }
    first = prev;
    prev = NULL;
    curr = second;
    next = NULL;
    while(curr != NULL){
        next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
    }
    second = prev;

    // add both lists
    Node* res = NULL;
    Node* temp = NULL;
    int carry = 0, sum = 0;
    while(first != NULL || second != NULL){
        sum = carry + (first ? first->data : 0) + (second ? second->data : 0);
        carry = (sum >= 10) ? 1 : 0;
        sum = sum % 10;
        temp = new Node(sum);
        if(res == NULL)
            res = temp;
        else{
            temp->next = res;
            res = temp;
        }
        if(first)
            first = first->next;
        if(second)
            second = second->next;
    }
    if(carry > 0){
        temp = new Node(carry);
        temp->next = res;
        res = temp;
    }
    return res; 
}

int main(){
    int t;
    cin>>t;
    while(t--){
        int n,m;
        cin>>n;
        Node* first = buildList(n);
        cin>>m;
        Node* second = buildList(m);
        Node* res = addTwoLists(first, second);
        printList(res);
        cout<<endl;
    }
    return 0;
}