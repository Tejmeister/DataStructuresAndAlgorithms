#include<bits/stdc++.h>
using namespace std;

void printArray(long long int arr[], long long int N){
    for(long long int i=0; i<N; i++)
        cout<<arr[i]<<" ";
    cout<<endl;
}

int main()
 {
	//code
    long long int T, N;
    cin>>T;
    while(T){
        cin>>N;
        long long int arr[N];
        for(long long int i=0; i<N; i++) cin>>arr[i];
        
        stack<long long int> s;
        long long int ans[N];
        for(long long int i=N-1; i>=0; i--){
            while(!s.empty() && arr[i] >= s.top()){
                s.pop();
            }
            ans[i] = s.empty() ? -1 : s.top();
            s.push(arr[i]);
        }
        printArray(ans,N);
        T--;
    }
	return 0;
}