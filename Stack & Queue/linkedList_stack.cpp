#include<bits/stdc++.h>
using namespace std;

class myStack {
    struct Node{
        int num ;
        Node *next;

        Node(int x){
            num = x;
            next = NULL;
        }
    };

    Node *head;
    int size;

public:
    
        myStack(){
            head = NULL;
            size = 0;
        }
    
        void push(int x){
            Node *temp = new Node(x);
            temp->next = head;
            head = temp;
            size++;
        }
    
        int pop(){
            if(head == NULL){
                return -1;
            }
            else{
                int x = head->num;
                Node *temp = head;
                head = head->next;
                delete temp;
                size--;
                return x;
            }
        }
    
        int top(){
            if(head == NULL){
                return -1;
            }
            else{
                return head->num;
            }
        }
    
        int getSize(){
            return size;
        }
    
        bool isEmpty(){
            return (head == NULL);
        }
    };

int main(){
    myStack s;

    s.push(10);
    s.push(20);
    s.push(30);

    cout<<s.top()<<endl;
    s.pop();
    cout<<s.top()<<endl;
    cout<<s.getSize()<<endl;
    cout<<s.isEmpty()<<endl;
}