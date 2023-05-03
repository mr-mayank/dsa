#include<bits/stdc++.h>
using namespace std;

int n;
int board[100][100];

bool isSafe(int row, int col){
    // check for the same column
    for(int i=0; i<row; i++){
        if(board[i][col] == 1){
            return false;
        }
    }
    // check for the left diagonal
    for(int i=row, j=col; i>=0 && j>=0; i--, j--){
        if(board[i][j] == 1){
            return false;
        }
    }
    // check for the right diagonal
    for(int i=row, j=col; i>=0 && j<n; i--, j++){
        if(board[i][j] == 1){
            return false;
        }
    }
    return true;
}

bool nQueen(int row){
    if(row == n){
        return true;
    }
    for(int col=0; col<n; col++){
        if(isSafe(row, col)){
            board[row][col] = 1;
            if(nQueen(row+1)){
                return true;
            }
            board[row][col] = 0;
        }
    }
    return false;
}

int main(){
    cin>>n;
    if(nQueen(0)){
        for(int i=0; i<n; i++){
            for(int j=0; j<n; j++){
                cout<<board[i][j]<<" ";
            }
            cout<<endl;
        }
    }
    else{
        cout<<"No solution exists"<<endl;
    }
    return 0;
}