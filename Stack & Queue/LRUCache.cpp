#include<bits/stdc++.h>
using namespace std;

class LRUCache{
    public:
    class Node{
        public:
        int key;
        int value;
        Node *next;
        Node *prev;
        Node(int k, int v){
            key = k;
            value = v;
            next = NULL;
            prev = NULL;
        }
    };
    Node *head = new Node(-1, -1);
    Node *tail = new Node(-1, -1);
    int cap;
    unordered_map<int, Node*> m;

    LRUCache(int capacity){
        cap = capacity;
        head->next = tail;
        tail->prev = head;
    }

    void addNode(Node *newNode){
        Node *temp = head->next;
        newNode->next = temp;
        newNode->prev = head;
        head->next = newNode;
        temp->prev = newNode;
    }

    void deleteNode(Node *delNode){
        Node *delPrev = delNode->prev;
        Node *delNext = delNode->next;
        delPrev->next = delNext;
        delNext->prev = delPrev;
    }

    int get(int key){
        if(m.find(key) != m.end()){
            Node *resNode = m[key];
            int res = resNode->value;
            m.erase(key);
            deleteNode(resNode);
            addNode(resNode);
            m[key] = head->next;
            return res;
        }
        return -1;
    }

    void set(int key, int value){
        if(m.find(key) != m.end()){
            Node *existNode = m[key];
            m.erase(key);
            deleteNode(existNode);
        }
        if(m.size() == cap){
            m.erase(tail->prev->key);
            deleteNode(tail->prev);
        }
        addNode(new Node(key, value));
        m[key] = head->next;
    }

};




int main(){
    LRUCache lru(2);
    lru.set(1, 10);
    cout<< lru.get(1) <<endl;
    return 0;
}