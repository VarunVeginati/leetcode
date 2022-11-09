class Solution {
public:
    int trap(vector<int>& height) {
        int left = 0;
        int right = height.size()-1;
        int left_max = 0;
        int right_max = 0;
        int ans = 0;
        
        while(left<right) {
            left_max = max(left_max, height[left]);
            right_max = max(right_max, height[right]);
            
            ans += (left_max-height[left]);
            ans += (right_max-height[right]);
            
            if(height[left]<height[right]) left++;
            else right--;
        }
        
        return ans;
    }
};