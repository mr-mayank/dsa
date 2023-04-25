#include<bits/stdc++.h>
using namespace std;

void kth_max_min(int arr[],int n,int k) {
    sort(arr,arr+n);
    cout << "Kth Max: " << arr[n-k] << endl;
    cout << "Kth Min: " << arr[k-1] << endl;
}

int main() {
    int n,k;
    cin >> n >> k;
    int arr[n];
    for(int i=0;i<n;i++) cin >> arr[i];
    kth_max_min(arr,n,k);
    return 0;
}