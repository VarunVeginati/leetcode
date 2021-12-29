class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        vector<int> left;
        vector<int> right(nums.size(),0);
        int cnt=0;
        
        for(int i=0; i<nums.size(); i++) {
            int n = k+(cnt*k);
            int max = nums[i];
            left.push_back(nums[i]);
            i++;
            while(i<nums.size() && i<n) {
                if(nums[i] > max)
                    max = nums[i];
                left.push_back(max);
                i++;
            }
            cnt++;
            i--;
        }
        
        cnt = nums.size()%k == 0 ? (nums.size()/k)-1 : nums.size()/k;
        
        for(int i=nums.size()-1; i>=0; i--) {
            int n = cnt*k;
            int max = nums[i];
            right[i] = nums[i];
            i--;
            while(i>=0 && i>=n) {
                if(nums[i] > max)
                    max = nums[i];
                right[i] = max;
                i--;
            }
            i++;
            cnt--;
        }
        
        vector<int> out;
        
        for(int i=0; i<nums.size()-k+1; i++) {
            out.push_back(max(right[i], left[i+k-1]));
        }
        
        return out;
    }
};