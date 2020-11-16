#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;

void printVector(vector<ll>& nums)
{
    for(ll i=0; i<nums.size(); i++)
        cout<<nums[i]<<" ";
    cout<<endl;
}
class Solution {
public:
    vector<long long int> productExceptSelf1(vector<long long int>& nums, int n) {
       
        //code here 
        ll left[n];
        ll right[n];
        
        left[0] = 1;
        right[n-1] = 1;
        
        for(int i=1; i<n; i++){
            left[i] = left[i-1]*nums[i-1];
        }
        
        for(int i=n-2; i>=0; i--){
            right[i] = right[i+1]*nums[i+1];
        }
        
        vector<ll> result;
        for(int i=0; i<=n; i++){
            result.push_back(left[i]*right[i]);
        }
        
        return result;
    }

    vector<long long int> productExceptSelf(vector<long long int>& nums, int n) {
       
        //code here 
        vector<ll> result(n,1);
        
        for(ll i=1; i<n; i++){
            result[i] = result[i-1]*nums[i-1];
        }

        ll rhs = 1;
        for(ll i=n-1; i>=1; i--){
            rhs = rhs*nums[i];
            result[i-1] *= rhs;
        }
        
        return result;
    }
};

int main(){
    //0,3,7,2,5,8,4,6,0,1
    vector<ll> arr;
    arr.push_back(10);
    arr.push_back(3);
    arr.push_back(5);
    arr.push_back(6);
    arr.push_back(2);

    
    Solution s;

    arr = s.productExceptSelf(arr, arr.size());

    printVector(arr);
    
    return 0;
}