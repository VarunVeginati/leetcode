class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        map<int,int> m;
        
        for(int i=0; i<nums.size(); i++) {
            int a = target-nums[i];
            if(m.find(a) != m.end()) return {i, m[a]};
            
            m[nums[i]]=i;
        }
        
        return {};
    }
};