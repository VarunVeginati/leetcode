class Solution {
public:
    int trap(vector<int>& height) {
        int n = height.size();
        int left_max = 0;
        int right_max = 0;
        vector<int> left;
        vector<int> right(n);
        int ans = 0;
        
        for(int i=0; i<n; i++) {
            left_max = max(height[i], left_max);
            right_max = max(height[n-i-1], right_max);
            left.push_back(left_max);
            right[n-i-1] = right_max;
        }
        
        for(int i=0; i<n; i++) {
            ans += min(left[i], right[i])-height[i];
        }
        
        return ans;
    }
};