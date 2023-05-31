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


Node* middle(Node* head){
    int count = 0;
    Node* temp = head;
    while(temp != NULL){
        count++;
        temp = temp->next;
    }
    temp = head;
    for(int i=0; i<count/2; i++){
        temp = temp->next;
    }
    return temp;

}
int main(){
    head = NULL;
    head = new Node(10);
    head->next = new Node(20);
    head->next->next = new Node(30);
    head->next->next->next = new Node(40);
    cout<<middle(head)->data<<endl;
    return 0;
}