#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int coinChange(vector<int>& coins, int n) {
        vector<int> dp(n+1, n+1);
        
        dp[0] = 0;
        
        for(int j=0; j<coins.size(); j++){
            for(int i=coins[j]; i<n+1; i++){
                dp[i] = min(dp[i-coins[j]] + 1, dp[i]);
            }
        }
        
        return dp[n]>=n+1? -1: dp[n];
    }
};

int main(){
    
    vector<int> coins;
    coins.push_back(1);
    coins.push_back(2);
    coins.push_back(5);

    int amount = 11;

    Solution s;
    cout<<s.coinChange(coins, amount);

    return 0;
}