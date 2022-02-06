class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int k = nums.size();
        int n = k;
        if(n==1) return 1;
        int j= 0;
        bool flag = true;
        
        for(int i=1; i<nums.size(); i++) {
            if(nums[i] == nums[i-1]) {
                if(!flag) {
                    k--;
                }
                else {
                    flag = false;
                    nums[++j] = nums[i];
                }
            } else {
                flag = true;
                nums[++j] = nums[i];
            }
        }
        
        return k;
    }
};