#include<bits/stdc++.h>
using namespace std;


int getMinDiff(int arr[], int n, int k){

    sort(arr, arr+n);

    int ans = arr[n-1] - arr[0];

    int max1, min1;
    max1 = arr[n-1];
    min1 = arr[0];

    for (int i = 1; i < n; i ++){
         if (arr[i] - k < 0){
            continue;
         }

     max1 = max(arr[i-1] + k, arr[n-1] - k);
     min1 = min(arr[0] + k, arr[i] - k);


    ans = min(ans, max1 - min1);
    }

    return ans;

}

int main(){
    int n,k;
    cin>>k>>n;

    int arr[n];
    for(int i=0;i<n;i++) cin>>arr[i];

    cout<<getMinDiff(arr,n,k)<<endl;


}