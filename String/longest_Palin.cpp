#include<bits/stdc++.h>
using namespace std;

bool isPalindrome(string s){
    int n = s.length();
    for(int i = 0; i<n/2; i++){
        if(s[i] != s[n-i-1]){
            return false;
        }
    }
    return true;
}
string maxPalin(string s){
    int n = s.length();
    string res = "";
    int maxLen = 0;
    for(int i=0;i<n;i++){
        for(int j=i;j<n;j++){
            string sub = s.substr(i,j-i+1);
            if(isPalindrome(sub) && sub.length() > maxLen){
                res = sub;
                maxLen = sub.length();
            }
        }
    }
    return res;

}

int main(){
    string s;
    cin >> s;
    cout << maxPalin(s);
    return 0;
}