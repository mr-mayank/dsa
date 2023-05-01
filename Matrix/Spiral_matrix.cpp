#include<bits/stdc++.h>
using namespace std;

vector<int> Spiral(vector<vector<int>> matrix , int n, int m){
    vector<int> res;
    int rowStart = 0, rowEnd = n-1, colStart = 0, colEnd = m-1;
    while(rowStart <= rowEnd && colStart <= colEnd){
        for(int col = colStart; col <= colEnd; col++){
            res.push_back(matrix[rowStart][col]);
        }
        rowStart++;
        for(int row = rowStart; row <= rowEnd; row++){
            res.push_back(matrix[row][colEnd]);
        }
        colEnd--;
        if(rowStart <= rowEnd){
            for(int col = colEnd; col >= colStart; col--){
                res.push_back(matrix[rowEnd][col]);
            }
            rowEnd--;
        }
        if(colStart <= colEnd){
            for(int row = rowEnd; row >= rowStart; row--){
                res.push_back(matrix[row][colStart]);
            }
            colStart++;
        }
    }
    return res;
    
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
    vector<int> res = Spiral(matrix,n,m);
    for(int i=0;i<res.size();i++){
        cout << res[i] << " ";
    }
    return 0;
}