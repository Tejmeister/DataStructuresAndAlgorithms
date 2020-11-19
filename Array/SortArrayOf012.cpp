#include<bits/stdc++.h>
using namespace std;


class Solution{   
public:
    void SortNums(int arr[], int n) {
        int zeroIndex = 0, oneIndex = 0, twoIndex = n-1;

        while(oneIndex <=    twoIndex){
            if(arr[oneIndex] == 0){
                swap(arr[oneIndex++], arr[zeroIndex++]);
            }
            else if(arr[oneIndex] == 1){
                oneIndex++;
            }
            else{
                swap(arr[oneIndex], arr[twoIndex--]);
            }
        }

    }
};

int main(){

	int arr[] = {0, 2, 1, 2, 0, 0, 2, 1, 0};
	int n = sizeof(arr)/sizeof(arr[0]);
	Solution s;
	s.SortNums(arr,n);

    for(int i=0; i<n; i++)
        cout<<arr[i]<<" ";

}