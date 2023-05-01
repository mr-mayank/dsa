#include<bits/stdc++.h>
using namespace std;

bool search(vector<vector<int>> matrix, int target){
    int n = matrix.size();
    int m = matrix[0].size();
    int i = 0, j = m-1;
    while(i < n && j >= 0){
        if(matrix[i][j] == target){
            return true;
        }
        else if(matrix[i][j] > target){
            j--;
        }
        else{
            i++;
        }
    }
    return false;
}

bool search1(vector<vector<int>> matrix, int target){
    int n = matrix.size();
    int m = matrix[0].size();

    for(int i = 0; i<n;i++){
        for(int j = 0; j<m;j++){
            if(matrix[i][j] == target){
                return true;
            }
        }
    }
    return false;
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
    int target;
    cin >> target;
    cout << search(matrix,target) << endl;
    cout << search1(matrix,target) << endl;
    return 0;
}