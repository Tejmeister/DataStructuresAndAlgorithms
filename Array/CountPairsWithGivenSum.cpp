#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int countPairs(vector<int>& nums, int target) {
        unordered_map<int, int> m;
        
        int count = 0;
        
        for(int i=0; i<nums.size(); i++){
            int pairElement = target - nums[i];
            if(m.find(pairElement) != m.end()){
                count++;
            }
            m.insert(pair<int, int>(nums[i],i));
        }
        return count;
    }
    
};

int main(){
    vector<int> arr;
    arr.push_back(2);
    arr.push_back(7);
    arr.push_back(11);
    arr.push_back(5);

    int k = 9;

    Solution s;

    cout<<s.countPairs(arr, k)<<endl;
    return 0;
}