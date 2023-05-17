#include<bits/stdc++.h>
using namespace std;
int p = 31;

const int N = 1e5 + 2, MOD = 1e9 + 7;
vector<long long> p_pow(N);

int main(){
    string s = "ababab";
    string t = "ab";
    int n = s.length(), m = t.length();
    p_pow[0] = 1;
    for(int i=1;i<N;i++){
        p_pow[i] = (p_pow[i-1] * p) % MOD;
    }
    vector<long long> h(n+1, 0);
    for(int i=0;i<n;i++){
        h[i+1] = (h[i] + (s[i] - 'a' + 1) * p_pow[i]) % MOD;
    }
    long long h_s = 0;
    for(int i=0;i<m;i++){
        h_s = (h_s + (t[i] - 'a' + 1) * p_pow[i]) % MOD;
    }
    vector<int> occurences;
    for(int i=0;i+m-1<n;i++){
        long long cur_h = (h[i+m] + MOD - h[i]) % MOD;
        if(cur_h == (h_s * p_pow[i]) % MOD){
            occurences.push_back(i);
        }
    }
    for(auto x: occurences){
        cout<<x<<" ";
    }
    cout<<endl;
    
    return 0;
}