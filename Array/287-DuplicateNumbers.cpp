#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int findDuplicate2(vector<int>& nums) {
        for(int i=0; i<nums.size(); i++){
            if(nums[abs(nums[i]) - 1] > 0){
                nums[abs(nums[i]) - 1] = -nums[abs(nums[i]) - 1];
            }
            else{
                return abs(nums[i]);
            }
        }
        return -1;
    }
    
    int findDuplicate(vector<int>& nums) {
        int slow = nums[0];
        int fast = nums[nums[0]];
        
        while(slow != fast){
            slow = nums[slow];
            fast = nums[nums[fast]];
        }
        
        fast = 0;
        
        while(fast != slow){
            fast = nums[fast];
            slow = nums[slow];
        }
        
        return slow;
    }
};

int main(){
    vector<int> arr;
    arr.push_back(1);
    arr.push_back(3);
    arr.push_back(4);
    arr.push_back(2);
    arr.push_back(5);
    arr.push_back(2);

    Solution s;
    cout<<s.findDuplicate(arr);

}