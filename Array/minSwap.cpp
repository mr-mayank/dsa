#include<bits/stdc++.h>
using namespace std;

int minSwap(int arr[], int n, int k){
    int count = 0;
    for(int i=0;i<n;i++){
        if(arr[i] <= k){
            count++;
        }
    }
    int bad = 0;
    cout << count << endl;
    for(int i=0;i<count;i++){
        if(arr[i] > k){
            bad++;
        }
    }
  cout << bad << endl;
    int ans = bad;
    for(int i=0,j=count;j<n;i++,j++){
        if(arr[i] > k){
            bad--;
        }
        if(arr[j] > k){
            bad++;
        }
        ans = min(ans, bad);
    }
    return ans;
}

int minSwap2(int arr[], int n, int k){
    int count = 0;
    for(int i=0;i<n;i++){
        if(arr[i] <= k){
            count++;
        }
    }

    int ans = INT_MAX;
    for(int i = 0, j = count; j < n; i++, j++){
        int bad = 0;
        for(int k = i; k < j; k++){
            if(arr[k] > k){
                bad++;
            }
        }
        ans = min(ans, bad);
    }
    return ans-1;
}

int main(){
   int n,k;
    cin >> n;
    cin >> k;
    int arr[n];
    for(int i=0;i<n;i++){
        cin >> arr[i];
    }
    cout << minSwap2(arr, n, k);
    return 0;
}