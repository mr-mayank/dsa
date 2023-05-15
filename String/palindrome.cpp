#include<bits/stdc++.h>
using namespace std;

bool isPalindrome(string s){
    int n = s.length();
    for(int i=0;i<n/2;i++){
        if(s[i] != s[n-i-1]){
            return false;
        }
    }
    return true;
}

int main(){
    string s;
    cin >> s;
    cout << isPalindrome(s);
    return 0;
}