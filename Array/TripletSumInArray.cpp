#include<bits/stdc++.h>
using namespace std;

void printArray(int arr[], int N){
    for(int i=0; i<N; i++)
        cout<<arr[i]<<" ";
    cout<<endl;
}

bool tripletExistsOld(int arr[], int n, int target){
    for(int i=0; i<n; i++){
        for(int j=i+1; j<n; j++){
            for(int k=j+1; k<n; k++){
                if(arr[i]+arr[j]+arr[k] == target)
                    return true;
            }
        }
    }
    
    return false;
}

bool tripletExists(int arr[], int n, int target){
    
    sort(arr, arr+n);
    
    for(int i=0; i<n-2; i++){
        int left = i+1;
        int right = n-1;
        
        while(left < right){
            int val = arr[i] + arr[left] + arr[right];
            if(val == target)
                return true;
            else if(val < target)
                left++;
            else
                right--;
        }
    }
    
    return false;
    
}

int main()
 {
	//code
    int T, N, X;
    cin>>T;
    while(T){
        cin>>N>>X;
        int arr[N];
        for(int i=0; i<N; i++) cin>>arr[i];
        
        cout<<tripletExists(arr, N, X)<<endl;
        
        T--;
    }
	return 0;
}