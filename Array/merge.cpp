#include<bits/stdc++.h>
using namespace std;

vector<vector<int>> merge(vector<vector<int>>& intervals) {
    vector<vector<int>> merged;

    sort(intervals.begin(), intervals.end());

    vector<int> temp = intervals[0];
    
    for(int i=1;i<intervals.size();i++){
        if(intervals[i][0] <= temp[1]){
            temp[1] = max(intervals[i][1], temp[1]);
        }
        else{
            merged.push_back(temp);
            temp = intervals[i];
        }
    }
    merged.push_back(temp);

    return merged;
}

int main(){
    vector<vector<int>> intervals = {{1,3},{2,6},{8,10},{15,18}};
    
    vector<vector<int>> merged = merge(intervals);

    for(int i=0;i<merged.size();i++){
        for(int j=0;j<merged[i].size();j++){
            cout<<merged[i][j]<<" ";
        }
        cout<<endl;
    }
    return 0;
}