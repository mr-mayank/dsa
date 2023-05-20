#include<bits/stdc++.h>
using namespace std;

const int R = 3, C = 3;

void printUntill(string arr[R][C], int m, int n, string out[R] ){
    out[m] = arr[m][n];

    if(m == R-1){
        for(int i=0;i<R;i++){
            cout<<out[i]<<" ";
        }
        cout<<endl;
        return;
    }

    for(int i=0;i<C;i++){
        if(arr[m+1][i] != ""){
            printUntill(arr, m+1, i, out);
        }
    }

}

void print(string arr[R][C]){
    string out[R];

    for(int i=0;i<C;i++){
        if(arr[0][i] != ""){
            printUntill(arr, 0, i, out);
        }
    }
}

int main(){
    string arr[R][C] = {{"you", "we"},
                        {"have", "are"},
                        {"sleep", "eat", "drink"}};

    print(arr);
}