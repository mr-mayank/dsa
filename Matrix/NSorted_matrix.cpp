#include<bits/stdc++.h>
using namespace std;

vector<vector<int>> sorted_matrix(int n, vector<vector<int>> matrix){
    vector<vector<int>> ans(n, vector<int>(n));
    
    vector<int> arr;
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            arr.push_back(matrix[i][j]);
        }
       
    }
     sort(arr.begin(),arr.end());
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                ans[i][j] = arr[i*n+j];
            }
        }
        
    return ans;
}


int main(){
    int n;
    cin >> n;
    vector<vector<int>> matrix(n, vector<int>(n));
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cin >> matrix[i][j];
        }
    }
    matrix = sorted_matrix(n, matrix);
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cout << matrix[i][j] << " ";
        }
        cout << endl;
    }
    return 0;
}