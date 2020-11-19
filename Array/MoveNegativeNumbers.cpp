#include<bits/stdc++.h>
using namespace std;


class Solution{   
public:
    void MoveNegativeNumbers(int arr[], int n) {
        int j = 0;
        for(int i=0; i<n; i++){
            if(arr[i] < 0){
                if(i != j)
                    swap(arr[i], arr[j]);
                j++;
            }

        }
    }
};

int main(){

	int arr[] = {-12, 11, -13, -5, 6, -7, 5, -3, -6};
	int n = sizeof(arr)/sizeof(arr[0]);
	Solution s;
	s.MoveNegativeNumbers(arr,n);

    for(int i=0; i<n; i++)
        cout<<arr[i]<<" ";

}