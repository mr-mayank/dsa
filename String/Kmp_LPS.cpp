#include <iostream>
#include <vector>
using namespace std;

int longestPrefixSuffix(const string& str) {
    int n = str.length();
    vector<int> lps(n, 0);

    int len = 0; 
    int i = 1;

    while (i < n) {
        if (str[i] == str[len]) { //blablabla -- b-b i=3, l-l,a-a,b-b,l-l,a-a
            len++; //len-6
            lps[i] = len; // lps[8]=6
            i++; //i=9
        } else {
            if (len != 0) {
                len = lps[len - 1];
            } else { //lps-0
                lps[i] = 0;
                i++;
            }
        }
    }

    return lps[n - 1]; //6
}

int main() {
   string s;
   cin>>s;
    int length = longestPrefixSuffix(s);
    cout << "Length of the longest prefix which is also a suffix: " << length << endl;
    return 0;
}