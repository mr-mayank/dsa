#include<bits/stdc++.h>
using namespace std;

// int middle(int A, int B, int C){
//     int x = A-B;
//     int y = B-C;
//     int z = A-C;
//     if(x*y>0)
//         return B;
//     else if(x*z>0)
//         return C;
//     else
//         return A;
// }

int middle(int A, int B, int C){
        //code here//Position this line where user code will be pasted.
        if( B > C){
            if(B < A){
                return B;
            }
        }
        else{
            if(B > A){
                return B;
            }
        }
        if( A > C){
            if(A < B){
                return A;
            }
        }
        else{
            if(A > B){
                return A;
            }
        }
        return C;
   
    }

int main(){
    int A,B,C;
    cin>>A>>B>>C;
    cout<<middle(A,B,C);
    return 0;
}