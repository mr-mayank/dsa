#include<bits/stdc++.h>
using namespace std;

string toNO(string s, int arr[], int n){
    string ans = "";
    for(int i=0;i<n;i++){
        if(s[i] == ' '){
            ans += '0';
        }
        else{
            int pos = s[i] - 'A';
            ans += to_string(arr[pos]);
        }
    }
    return ans;
}
int main(){
    int arr[]= {
        2,22,222,3,33,333,4,44,444,5,55,555,6,66,666,7,77,777,7777,8,88,888,9,99,999,9999};

        string s;
        cin>>s;
        int n = s.length();

        string ans = toNO(s, arr, n);

        cout<<ans<<endl;


}