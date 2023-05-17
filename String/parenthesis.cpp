#include<bits/stdc++.h>
using namespace std;

bool isOpening(char c){
    return (c == '(' || c == '{' || c == '[');
}

bool isClosing(char c){
    return (c == ')' || c == '}' || c == ']');
}

bool isPar(string s){
    stack<char> st ;
    for(int i=0;i<s.length();i++){
        char c = s[i];
        if(isOpening(c)){
            st.push(c);
        }
        else if(isClosing(c)){
            if(st.empty()){
                return false;
            }
            char top = st.top();
            st.pop();
            if((top == '(' && c != ')') || (top == '{' && c != '}') || (top == '[' && c != ']')){
                return false;
            }
        }
    }
    return st.empty();
}

int main(){
    string s;
    cin>>s;
    cout<<isPar(s)<<endl;
    return 0;
}