#include<bits/stdc++.h>
using namespace std;

class nStacks{
    int *arr;
    int *top;
    int *next;
    int free;
    int k;
    int n;

    public:
        nStacks(int k1, int n1){
            k = k1;
            n = n1;
            arr = new int[n];
            top = new int[k];
            next = new int[n];

            for(int i = 0; i < k; i++){
                top[i] = -1;
            }

            free = 0;
            for(int i = 0; i < n-1; i++){
                next[i] = i+1;
            }
            next[n-1] = -1;
        }

        void push(int x, int sn){
            if(free == -1){
                cout << "Stack Overflow\n";
                return;
            }

            int i = free;
            free = next[i];
            next[i] = top[sn];
            top[sn] = i;
            arr[i] = x;
        }

        int pop(int sn){
            if(top[sn] == -1){
                cout << "Stack Underflow\n";
                return INT_MAX;
            }

            int i = top[sn];
            top[sn] = next[i];
            next[i] = free;
            free = i;
            return arr[i];
        }

        bool isEmpty(int sn){
            return (top[sn] == -1);
        }
};

int main(){
    int k = 3, n = 10;
    nStacks ns(k, n);

    ns.push(15, 2);
    ns.push(45, 2);

    ns.push(17, 1);
    ns.push(49, 1);
    ns.push(39, 1);
    ns.push(39, 1);
    ns.push(39, 1);
    ns.push(39, 1);

    ns.push(11, 0);
    ns.push(9, 0);
    ns.push(7, 0);
    ns.push(7, 0);

    // cout << "Popped element from stack 2 is " << ns.pop(2) << endl;
    // cout << "Popped element from stack 2 is " << ns.pop(2) << endl;
    // cout << "Popped element from stack 1 is " << ns.pop(1) << endl;
    // cout << "Popped element from stack 0 is " << ns.pop(0) << endl;

    return 0;
}