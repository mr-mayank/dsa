#include<bits/stdc++.h>
using namespace std;

string reverse(string s){
    int n = s.length();
    for(int i=0;i<n/2;i++){
        swap(s[i],s[n-i-1]);
    }
    return s;
}

string reverse2(string s){
    int n = s.length();
    string res = "";
    for(int i=n-1;i>=0;i--){
        res += s[i];
    }
    return res;
}


int main(){
    string s;
    cin >> s;
    cout << reverse(s);
    return 0;
}