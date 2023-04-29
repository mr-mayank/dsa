#include<bits/stdc++.h>
using namespace std;

vector<vector<int>> next_perm(vector<int> nums){
    vector<vector<int>> res;
    int n = nums.size();
    int i = n-1;
   
    while(i>0 && nums[i-1] >= nums[i]){
        i--;
    }
    if(i==0){
        sort(nums.begin(), nums.end());
        res.push_back(nums);
        return res;
    }
    int j = n-1;
    while(nums[j] <= nums[i-1]){
        j--;
    }
    // cout<<i<<" "<<j<<endl;
    swap(nums[i-1], nums[j]);
     
    sort(nums.begin()+i, nums.end());
   
    res.push_back(nums);
    return res;
}

int main(){
    vector<int> nums = {1,2,3};
    vector<vector<int>> res = next_perm(nums);
    for(int i=0;i<res.size();i++){
        for(int j=0;j<res[i].size();j++){
            cout<<res[i][j]<<" ";
        }
        cout<<endl;
    }
    return 0;
}

