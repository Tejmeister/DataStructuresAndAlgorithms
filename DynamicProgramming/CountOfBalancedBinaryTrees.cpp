#include<bits/stdc++.h>
using namespace std;

#define mod 1000000007

class Solution {
public:
    int countBinaryTreesRecursion(int h) {
        if(h==0 || h==1)
            return 1;
        return countBinaryTreesRecursion(h-1)*(2*countBinaryTreesRecursion(h-2)+countBinaryTreesRecursion(h-1));           
    }

    long long int countBinaryTrees(int h){
        if(h==0 || h==1)
            return 1;
        long long int dp[h+1];
        dp[0] = 1;
        dp[1] = 1;

        for(long long int i=2; i<=h; i++){
            dp[i] = (dp[i-1]*(2*dp[i-2]%mod + dp[i-1])%mod)%mod;
        }

        return dp[h];
    }
};


int main(){
    int h = 4;
    Solution s;
    cout<<s.countBinaryTrees(h);
}