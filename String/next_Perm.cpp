#include<bits/stdc++.h>
using namespace std;

vector<int> nextPermutation(int n, vector<int> arr){
    int index = -1;
    for(int i=n-2;i>0;i--){
        if(arr[i] < arr[i+1]){
            index = i;
            break;
        }
    }
    if(index == -1){
        sort(arr.begin(), arr.end());
        return arr;
    }
    for(int i = n-1;i>index;i--){
        if(arr[i] > arr[index]){
            swap(arr[i], arr[index]);
            break;
        }
    }
    sort(arr.begin()+index+1, arr.end());
    return arr;
}

int main(){
    int n;
    cin>>n;
    vector<int> arr(n);
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    
    vector<int> res = nextPermutation(n, arr);
    for(int i=0;i<n;i++){
        cout<<res[i]<<" ";
    }
    cout<<endl;
    return 0;
}