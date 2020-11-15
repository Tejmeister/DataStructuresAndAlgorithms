#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int minPrice = INT_MAX;
        int maxProfit = 0;
        for(int i=0; i<prices.size(); i++){
            if(prices[i] < minPrice)
                minPrice = prices[i];
            else if(prices[i]-minPrice > maxProfit)
                maxProfit = prices[i] - minPrice;
        }
        return maxProfit;
    }
    
};


int main(){
    vector<int> arr;
    arr.push_back(7);
    arr.push_back(1);
    arr.push_back(5);
    arr.push_back(3);
    arr.push_back(6);
    arr.push_back(4);


    Solution s;
    cout<<s.maxProfit(arr)<<endl;
    return 0;
}