#include<bits/stdc++.h>
using namespace std;

void Duplicates(string s){
    int n = s.length();
    int freq[26] = {0};
    for(int i=0;i<n;i++){
        freq[s[i]-'a']++;
    }
    for(int i=0;i<26;i++){
        if(freq[i] > 1){
            cout << (char)(i+'a') << " " << freq[i] << endl;
        }
    }
}

void dups(string s){
    int n = s.length();
    map<char,int> freq;
    for(int i=0;i<n;i++){
        freq[s[i]]++;
    }

    for(auto it:freq){
        if(it.second > 1){
            cout << it.first << " " << it.second << endl;
        }
    }

}
int main(){
    string s;
    cin >> s;
    Duplicates(s);
    dups(s);
    return 0;
}