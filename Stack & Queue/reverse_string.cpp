#include<bits/stdc++.h>
using namespace std;

void reverse(string &s){
    stack<char> st;
    for(int i = 0; i < s.length(); i++){
        st.push(s[i]);
    }
    for(int i = 0; i < s.length(); i++){
        s[i] = st.top();
        st.pop();
    }
}

int main(){
    string s;
    cin >> s;
    reverse(s);
    cout << s << endl;
    return 0;
}