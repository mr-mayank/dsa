#include<bits/stdc++.h>
using namespace std;

string nonRepeat(string str){
    queue<char> q;
    string res = "";
    int count[26] = {0};
    for(int i=0; i<str.length(); i++){
        q.push(str[i]);
        count[str[i]-'a']++;
        while(!q.empty()){
            if(count[q.front()-'a'] > 1){
                q.pop();
            }
            else{
                res += q.front();
                break;
            }
        }
        if(q.empty()){
            res += '#';
        }
    }
    return res;
}

int main(){
   string str;
    cin>>str;
    cout<<nonRepeat(str)<<endl;
    return 0;
}