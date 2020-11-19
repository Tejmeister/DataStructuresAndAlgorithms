#include<bits/stdc++.h>
#define ll long long

using namespace std;

void printArray(ll arr[], ll N){
    for(ll i=0; i<N; i++)
        cout<<arr[i]<<" ";
    cout<<endl;
}

int main()
 {
	//code
    ll T, N;
    cin>>T;
    while(T){
        cin>>N;
        ll arr[N];
        for(ll i=0; i<N; i++) cin>>arr[i];
        
        stack<ll> s;
        ll ans[N];
        //s.push(arr[0]);
        for(ll i=N-1; i>=0; i--){
            //next = arr[i];
            while(!s.empty() && arr[i] < s.top()){
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