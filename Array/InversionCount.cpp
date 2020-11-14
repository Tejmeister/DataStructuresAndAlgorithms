#include<bits/stdc++.h>
using namespace std;

typedef long long int ll;

class Solution{
public:
	// TLE for large inputs
	long long int inversionCountTLE(long long arr[], long long N)
	{
	    // Your Code Here
	    long long int count = 0;
	    for(long long i=0; i<N; i++){
	        for(long long j=i+1; j<N; j++){
	            if(arr[i] > arr[j])
	                count++;
	        }
	    }
	    
	    return count;
	}

	long long int merge(ll arr[], ll temp[], ll left, ll mid, ll right){
		ll i = left;
		ll j = mid;
		ll k = left;

		ll invCount = 0;

		while(i<mid && j<=right){
			if(arr[i] <= arr[j])
				temp[k++] = arr[i++];
			else{
				temp[k++] = arr[j++];

				invCount += (mid - i);
			}
		}

		while(i<mid){
			temp[k++] = arr[i++];
		}

		while(j<= right)
			temp[k++] = arr[j++];

		for(i = left; i<=right; i++){
			arr[i] = temp[i];
		}

		return invCount;
	}

	long long int mergerSort(long long arr[], long long temp[], long long int left, long long int right){
		long long int mid, invCount = 0;
		if(left < right){
			mid = (right+left)/2;

			invCount += mergerSort(arr, temp, left, mid);

			invCount += mergerSort(arr, temp, mid+1, right);

			invCount += merge(arr, temp, left, mid+1, right);
		}

		return invCount;
	}

	long long int inversionCount(long long arr[], long long int N)
	{
	    // Your Code Here
	    long long temp[N];
	    return mergerSort(arr, temp, 0, N);
	}
};

int main(){
	long long int arr[] = {4,1,2,3,5};
	long long int N = sizeof(arr)/sizeof(arr[0]);

	Solution s;
	cout<<s.inversionCount(arr, N);
	return 0;
}