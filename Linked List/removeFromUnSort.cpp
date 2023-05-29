#include<bits/stdc++.h>
using namespace std;

class Node{
    public:
    int data;
    Node* next;

    Node(int data){
        this->data=data;
        this->next =NULL;
    }

};

Node* removeDuplicatesFromUnSortedList(Node *head)
{
    Node* temp = head;
    Node* prev = NULL;
    unordered_set<int> s;
    while(temp!=NULL){
        if(s.find(temp->data)!=s.end()){
            prev->next = temp->next;
            delete(temp);
        }
        else{
            s.insert(temp->data);
            prev = temp;
        }
        temp = prev->next;
    }
    return head;
}



void insertAtEnd(Node* &head, int data){
    Node* newNode = new Node(data);
    if(head==NULL){
        head = newNode;
        return;
    }
    Node* temp = head;
    while(temp->next!=NULL){
        temp = temp->next;
    }
    temp->next = newNode;
}

void print(Node* head){
   Node* temp = head;
   while(temp!=NULL){
       cout<<temp->data<<" ";
       temp = temp->next;
   }
}

int main(){
    Node* node1 = new Node(10);


    insertAtEnd(node1, 20);
    insertAtEnd(node1, 50);
    insertAtEnd(node1, 40);
    insertAtEnd(node1, 20);
    insertAtEnd(node1, 30);

    print(node1);

    cout<<endl;


    Node* head2 = removeDuplicatesFromUnSortedList(node1);
    print(head2);

    return 0;

}