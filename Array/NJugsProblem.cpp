#include<bits/stdc++.h>

using namespace std;

int getMaxWater(int capacity[], int n){
	int minimum = capacity[0];
	int result = 0;
	for(int i=0; i<n; i++){
		minimum = min(minimum,capacity[i]);
		result += minimum;
	}

	return result;
}

int main(){
	int T = 2;
	int n = 4;
	int arr[] = {10,4,7,3};

	// int n = 5;
	// int arr[] = {1,2,3,4,5};

	cout<<getMaxWater(arr, n);

	return 0;
}