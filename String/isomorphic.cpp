#include<bits/stdc++.h>
using namespace std;

bool AreIso(string s1, string s2){
    int n1 = s1.length();
    int n2 = s2.length();

    if(n1 != n2){
        return false;
    }

   vector<int> m1(256,-1);
    vector<int> m2(256,-1);

    for(int i=0;i<n1;i++){
        cout<<m1[s1[i]]<<" "<<m2[s2[i]]<<endl;
        if(m1[s1[i]] != m2[s2[i]]){
            return false;
        }

        m1[s1[i]] = i;
        m2[s2[i]] = i;
    }

    return true;
}

int main(){
    string s1,s2;
    cin>>s1>>s2;

    bool ans = AreIso(s1,s2);

    if(ans){
        cout<<"Yes"<<endl;
    }else{
        cout<<"No"<<endl;
    }
}