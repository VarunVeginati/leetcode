class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        map<int,int> hashmap;
        hashmap[0] = 1;
        
        int sum = 0;
        int cnt = 0;
        
        for(int i=0; i<nums.size(); i++) {
            sum += nums[i];
            cnt += hashmap[sum-k];
            hashmap[sum]++;
        }
        
        return cnt;
    }
};