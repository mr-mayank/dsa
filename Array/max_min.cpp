#include<bits/stdc++.h>
using namespace std;

void max_min(int arr[],int n) {
    int max=INT_MIN,min=INT_MAX;
    for(int i=0;i<n;i++) {
        if(arr[i]>max) max=arr[i];
        if(arr[i]<min) min=arr[i];
    }
    cout << "Max: " << max << endl;
    cout << "Min: " << min << endl;
}

void max_min1(int arr[], int n){
    // take two parameters, the beginning of the
    // array and the length n upto which we want the array to
    // be sorted
    sort(arr,arr+n);
    cout << "Max: " << arr[n-1] << endl;
    cout << "Min: " << arr[0] << endl;
}

int main() {
    int n;
    cin >> n;
    int arr[n];
    for(int i=0;i<n;i++) cin >> arr[i];
    max_min1(arr,n);
    return 0;
}