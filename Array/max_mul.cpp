#include<bits/stdc++.h>
using namespace std;

int maxProduct(int* arr, int n)
{

    int minVal = arr[0];
    int maxVal = arr[0];

    int maxProduct = arr[0];

    for (int i = 1; i < n; i++) {

        // When multiplied by -ve number,
        // maxVal becomes minVal
        // and minVal becomes maxVal.
        if (arr[i] < 0)
            swap(maxVal, minVal);

        // maxVal and minVal stores the
        // product of subarray ending at arr[i].
        maxVal = max(arr[i], maxVal * arr[i]);
        minVal = min(arr[i], minVal * arr[i]);

        cout<<maxVal<<" "<<minVal<<endl;

        // Max Product of array.
        maxProduct = max(maxProduct, maxVal);
    }

    // Return maximum product found in array.
    return maxProduct;
}
   
long long maxProduct1(vector<long long> arr, int n) {
    long long maxVal = arr[0];
    long long minVal = arr[0];
    long long maxProduct = arr[0];
    for(int i=1;i<n;i++) {
        if(arr[i]<0) {
            swap(maxVal,minVal);
        }
        maxVal = max(arr[i],maxVal*arr[i]);
        minVal = min(arr[i],minVal*arr[i]);
        maxProduct = max(maxProduct,maxVal);
    }
    return maxProduct;
}

long long maxProduct3(vector<int> arr, int n) {
	    // Variables to store maximum and minimum
	    // product till ith index.
	    long long minVal = arr[0];
	    long long maxVal = arr[0];

	    long long maxProduct = arr[0];

	    for (int i = 1; i < n; i++) {

	        // When multiplied by -ve number,
	        // maxVal becomes minVal
	        // and minVal becomes maxVal.
	        if (arr[i] < 0) swap(maxVal, minVal);

	        // maxVal and minVal stores the
	        // product of subarray ending at arr[i].
	        maxVal = max((long long)arr[i], maxVal * arr[i]);
	        minVal = min((long long)arr[i], minVal * arr[i]);

	        // Max Product of array.
	        maxProduct = max(maxProduct, maxVal);
	    }

	    // Return maximum product found in array.
	    return maxProduct;
	}

int main(){
    int n;
    cin>>n;
    int arr[n];
    for(int i=0;i<n;i++) cin>>arr[i];

    cout << "Maximum Subarray product is "
         << maxProduct(arr, n) << endl;

    vector<int> arr1;
    for(int i=0;i<n;i++) arr1.push_back(arr[i]);
    cout << "Maximum Subarray product is "
         << maxProduct3(arr1, n) << endl;
    return 0;
}