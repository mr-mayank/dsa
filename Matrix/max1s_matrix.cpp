#include<bits/stdc++.h>
using namespace std;

int max1s_row(vector<vector<int>> matrix, int n ,int m){
 
    int max1s = 0;
    int row = -1;
    for(int i=0;i<n;i++){
        int count = 0;
        for(int j=0;j<m;j++){
            if(matrix[i][j] == 1){
                count++;
            }
        }
        if(count > max1s){
            max1s = count;
            row = i;
        }
    }
    return row;
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
    cout << max1s_row(matrix,n,m) << endl;
    return 0;
}