#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int OldmaxProduct(vector<int>& nums) {
        int current_min_product = nums[0];
        int current_max_product = nums[0];
        int previous_min_product = nums[0];
        int previous_max_product = nums[0];
        
        int result = nums[0];
        
        for(int i=1; i<nums.size(); i++){
            current_max_product = max(previous_max_product*nums[i], max(previous_min_product*nums[i], nums[i]));
            
            current_min_product = min(previous_max_product*nums[i], min(previous_min_product*nums[i], nums[i]));

            result = max(result, current_max_product);
            
            previous_min_product = current_min_product;
            previous_max_product = current_max_product;
        }
        
        return result;
    }
    
    int maxProduct(vector<int>& nums) {
        int current_min_product = nums[0];
        int current_max_product = nums[0];
        
        int result = nums[0];
        
        for(int i=1; i<nums.size(); i++){
            if(nums[i] < 0)
                swap(current_max_product, current_min_product);

            current_max_product = max(nums[i], current_max_product*nums[i]);
            current_min_product = min(nums[i], current_min_product*nums[i]);
            result = max(result, current_max_product);

        }
        
        return result;
    }
};

int main(){
    vector<int> arr;
    arr.push_back(2);
    arr.push_back(3);
    arr.push_back(-2);
    arr.push_back(4);

    Solution s;
    cout<<s.maxProduct(arr)<<endl;
    return 0;
}