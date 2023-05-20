#include<bits/stdc++.h>
using namespace std;

string smallest(string s1, string s2){
    int n1 = s1.length();
    int n2 = s2.length();

    int arr[26] = {0};

    for(int i=0;i<n2;i++){
        arr[s2[i] - 'a']++;
    }

    int count = 0;
    int start = 0;
    int start_index = -1;
    int min_len = INT_MAX;

    for(int i=0;i<n1;i++){
        arr[s1[i] - 'a']--;

        if(arr[s1[i] - 'a'] >= 0){
            count++;
        }

        if(count == n2){
            while(arr[s1[start] - 'a'] < 0){
                arr[s1[start] - 'a']++;
                start++;
            }

            int len = i - start + 1;
            if(len < min_len){
                min_len = len;
                start_index = start;
            }
        }
    }

    if(start_index == -1){
        return "-1";
    }

    return s1.substr(start_index, min_len);

}

int main(){
    string s1,s2;
    cin>>s1>>s2;

    string ans = smallest(s1,s2);

    cout<<ans<<endl;
}