class Solution {
public:
    int minMoves2(vector<int>& nums) {
        if(nums.size()==1) return 0;
        sort(nums.begin(), nums.end());
        
        int res1 = 0;
        int res2 = 0;
        
        int mid = nums[nums.size()/2];
        int mid1 = nums[nums.size()/2-1];
        for(int i=0; i<nums.size(); i++) {
            res1 += abs(nums[i]-mid);
            if(nums.size()%2==0) {
                res2 += abs(nums[i]-mid1);
            }
        }
        
        if(nums.size()%2 != 0) return res1;
        else return min(res1, res2);
    }
};