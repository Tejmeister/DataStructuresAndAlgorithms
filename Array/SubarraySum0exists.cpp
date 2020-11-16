#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool subArrayExists(vector<int>& nums) {
        unordered_set<int> sumSet;
        
        int sum = 0;
        
        for(int i=0; i<nums.size(); i++){
            sum += arr[i];
        
            if(sum == 0 || sumSet.find(sum) != sumSet.end())
                return true;
                
            sumSet.insert(sum);
        }
        
        return false;
    }
    
};

int main(){
    vector<int> arr;
    arr.push_back(2);
    arr.push_back(7);
    arr.push_back(11);
    arr.push_back(5);

    Solution s;
    cout<<s.subArrayExists(arr)<<endl;
    return 0;
}