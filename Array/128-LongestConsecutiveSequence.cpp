#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int longestConsecutive1(vector<int>& nums) {
        if(nums.size() == 0)
            return 0;
        sort(nums.begin(), nums.end());
    
        int lc = 1;
        int f = 1;
        
        for(int i=1; i<nums.size(); i++){
            if(nums[i] != nums[i-1]){
            if(nums[i] == nums[i-1] + 1)
                lc++;
            else{
                f = max(lc, f);
                lc = 1;
            }
            }
        }
        
        return max(f, lc);
    }
    
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> s(nums.begin(), nums.end());

        int f = 0;
        
        for(int i=0; i<nums.size(); i++){
            int lc = 1;
            if(s.find(nums[i]-1) == s.end()){
                int k = 1;
                while(s.find(nums[i]+k) != s.end()){
                    k++;
                    lc++;
                }
            }
            f = max(lc, f);
        }
        
        return f;
    }
};

int main(){
    //0,3,7,2,5,8,4,6,0,1
    vector<int> arr;
    arr.push_back(0);
    arr.push_back(3);
    arr.push_back(7);
    arr.push_back(2);
    arr.push_back(5);
    arr.push_back(8);
    arr.push_back(4);
    arr.push_back(6);
    arr.push_back(0);
    arr.push_back(1);
    
    Solution s;
    cout<<s.longestConsecutive(arr)<<endl;
    return 0;
}