#include <bits/stdc++.h>
using namespace std;

int palindrom(int arr, int n)
{
    int temp, r, sum = 0;
        temp = arr;
        while (arr > 0)
        {
            r = arr % 10;
            sum = (sum * 10) + r;
            arr = arr / 10;
        }
        if (temp == sum)
            return true;
        else
            return false;
    }

    

int main()
{
    int n, arr[20],f=0;
    bool palin[20];
    cin >> n;
  
    for (int i = 1; i < n + 1; i++)
    {
        cin >> arr[i];
        palin[i]= palindrom(arr[i], n);
        if(palin[i]==0){
            f=f+1;
        }
    
    }
    if(f>=1){
        cout<<"0";
    }else{
        cout<<"1";
    }

    return 0;
}