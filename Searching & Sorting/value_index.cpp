#include<bits/stdc++.h>
using namespace std;

vector<int> valueEqualToIndex(int arr[], int n){
    vector<int> ans;

    for(int i=0;i<n;i++){
        if(arr[i] == i+1){
            ans.push_back(i+1);
        }
    }

    return ans;
}

int main(){
    int n;
    cin>>n;

    int arr[n];
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }

    vector<int> ans = valueEqualToIndex(arr,n);

    for(int i=0;i<ans.size();i++){
        cout<<ans[i]<<" ";
    }
    cout<<endl;
}