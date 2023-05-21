#include<bits/stdc++.h>
using namespace std;

vector<int> find(vector<int> arr, int n, int x){
    int first = -1;
    int last = -1;

    for(int i=0;i<n;i++){
        if(x != arr[i]){
            continue;
        }

        if(first == -1){
            first = i;
        }

        last = i;
    }

    vector<int> ans;
    ans.push_back(first);
    ans.push_back(last);

    return ans;
}

int main(){
    int n,x;
    cin>>n>>x;

    vector<int> arr(n);
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }

    vector<int> ans = find(arr,n,x);

    cout<<ans[0]<<" "<<ans[1]<<endl;
}