#include<bits/stdc++.h>
using namespace std;

long long int factorial(int n){
    if(n==0){
        return 1;
    }
    return n*factorial(n-1);
}

vector<int> factorial1(int n){
    vector<int> res;
    res.push_back(1);

    for(int i=2;i<=n;i++){
        int carry = 0;
        for(int j=0;j<res.size();j++){
            int prod = res[j]*i + carry;
            res[j] = prod%10;
            carry = prod/10;
        }
        while(carry){
            res.push_back(carry%10);
            carry = carry/10;
        }
    }
    reverse(res.begin(), res.end());
    return res;
}

int main(){
    int n;
    cin>>n;
    vector<int> res = factorial1(n);
    for(int i=0;i<res.size();i++){
        cout<<res[i];
    }
    return 0;
}