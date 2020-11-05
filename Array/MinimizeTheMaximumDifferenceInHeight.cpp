#include<bits/stdc++.h>
using namespace std;


class Solution{   
public:
    int getMinDiff(int arr[], int n, int k) {
        // code here
        
        sort(arr, arr+n);
        int maxHeight = INT_MIN;
        int minHeight = INT_MAX;
        
        for(int i=0; i<n; i++){
            maxHeight = max(maxHeight, arr[i]);
            minHeight = min(minHeight, arr[i]);
        }
        
        if((maxHeight-minHeight) <=k)
            return maxHeight - minHeight;
        
        int avg = (maxHeight+minHeight)/2;
        
        for(int i=0; i<n; i++){
            if(arr[i] > avg)
                arr[i] -= k;
            else
                arr[i] += k;
        }
        
        maxHeight = INT_MIN;
        minHeight = INT_MAX;
        
        for(int i=0; i<n; i++){
            maxHeight = max(maxHeight, arr[i]);
            minHeight = min(minHeight, arr[i]);
        }
        
        return (maxHeight - minHeight);
    }
};

int main(){

	int arr[] = {1, 5, 8, 10};
	int n = sizeof(arr)/sizeof(arr[0]);
	int k = 2;
	Solution s;
	cout<<s.getMinDiff(arr,n, k)<<endl;
}