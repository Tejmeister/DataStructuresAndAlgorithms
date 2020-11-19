class Solution {
public:
    int trap(vector<int>& height) {
        int water = 0;
        
        int n = height.size();
        
        if(n<1)
            return water;
        
//         vector<int> left(n);
//         vector<int> right(n);
        
//         left[0] = height[0];
//         for(int i=1; i<n; i++){
//             left[i] = max(height[i], left[i-1]);
//         }
        
//         right[n-1] = height[n-1];
//         for(int i=n-2; i>=0; i--){
//             right[i] = max(height[i], right[i+1]);
//         }
        
//         for(int i=0; i<n; i++){
//             water += (min(left[i],right[i]) - height[i]);
//         }
        
        int low = 0, high = n-1;
        int leftMax = 0, rightMax = 0;
        
        while(low <= high){
            if(height[low] < height[high]){
                if(height[low]>leftMax){
                    leftMax = height[low];
                }
                else{
                    water += leftMax - height[low];
                }
                low++;
            }
            else{
                if(height[high] > rightMax){
                    rightMax = height[high];
                }
                else{
                    water += rightMax - height[high];
                }
                high--;
            }
        }
        
        return water;
    }
};
