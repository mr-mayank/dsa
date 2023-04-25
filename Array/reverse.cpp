#include<bits/stdc++.h>
using namespace std;

void reverse2(int arr[],int n) {
    for(int i=0;i<n/2;i++) {
        swap(arr[i],arr[n-i-1]);
    }
}

void reverse3(int arr[],int n) {
    int temp[n];
    for(int i=0;i<n;i++)
     temp[i]=arr[i];
    for(int i=0;i<n;i++) 
      arr[i]=temp[n-i-1];
}

int main() {
    int n;
    cin >> n;
    int arr[n];
    for(int i=0;i<n;i++) cin >> arr[i];
    reverse3(arr,n);
    for(int i=0;i<n;i++) cout << arr[i] << " ";
    return 0;
}