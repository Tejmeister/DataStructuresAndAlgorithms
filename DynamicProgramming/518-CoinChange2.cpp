#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int coinChange(vector<int>& S, int n) {
        vector<int> dp(n+1, 0);
        
        dp[0] = 1;
        
        for(int i=0; i<S.size(); i++){
            for(int j=S[i]; j<n+1; j++){
                dp[j] += dp[j-S[i]]; 
                
            }
        }
        
        return dp[n];
    }
};

int main(){
    
    vector<int> coins;
    coins.push_back(1);
    coins.push_back(2);
    coins.push_back(5);

    int amount =5;

    Solution s;
    cout<<s.coinChange(coins, amount);

    return 0;
}