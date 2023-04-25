#include<bits/stdc++.h>
using namespace std;

void sum_contigous(int arr[],int n) {
    int max=INT_MIN;
    for(int i=0;i<n;i++) {
        int sum=0;
        for(int j=i;j<n;j++) {
            sum+=arr[j];
            if(sum>max) max=sum;
        }
    }
    cout << "Max: " << max << endl;
}

int main() {
    int n;
    cin >> n;
    int arr[n];
    for(int i=0;i<n;i++) cin >> arr[i];
    sum_contigous(arr,n);
    return 0;
}