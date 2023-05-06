#include<bits/stdc++.h>
using namespace std;

int median(vector<vector<int>> matrix , int n, int m){    
   
   vector<int> arr;
    for(int i=0;i<n;i++){
         for(int j=0;j<m;j++){
              arr.push_back(matrix[i][j]);
         }
    }
    sort(arr.begin(),arr.end());
    int mid = (n*m)/2;
    return arr[mid];
}

int main(){
    int n,m;
    cin >> n >> m;
    vector<vector<int>> matrix(n, vector<int>(m));
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cin >> matrix[i][j];
        }
    }
    cout << median(matrix, n, m) << endl;
    return 0;
}