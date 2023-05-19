#include<bits/stdc++.h>
using namespace std;

int prefix_function(string s){
    int n = s.length();
    vector<int> pi(n);
    for(int i=1;i<n;i++){
        int j = pi[i-1];
        while(j > 0 && s[i] != s[j]){
            j = pi[j-1];
        }
        if(s[i] == s[j]){
            j++;
        }
        pi[i] = j;
    }
    vector<int> ans;
    for(int i=1;i<n;i++){
        if(pi[i] == pi[n-1]){
            ans.push_back(pi[i]);
        }
    }
    if(ans.size() == 0){
        cout<<"Just a legend"<<endl;
        return 0;
    }
    int mx = *max_element(ans.begin(), ans.end());
    return mx;

   
}

int main(){
    string s;
    cin>>s;
    int n = s.length();
    int mx = prefix_function(s);
    
    cout<< mx<<endl;
    

    

    return 0;
}