class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        if(nums.size()==0) return 0;
        sort(nums.begin(), nums.end());
        int mx_seq = 1;
        int seq = 1;
        
        for(int i=1; i<nums.size(); i++) {
            if(nums[i] == nums[i-1]+1) {
                seq++;
                mx_seq = max(mx_seq,seq);
            } else if(nums[i] != nums[i-1]) {
                seq=1;
            }
        }
        
        return max(mx_seq,seq);
    }
};