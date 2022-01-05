class Solution {
public:
    int majorityElement(vector<int>& nums) {
        map<int,int> m;
        int n = nums.size()-1;
        for(int i=0; i<nums.size(); i++) {
            m[nums[i]]++;
            if(m[nums[i]] > (n/2)) return nums[i];
        }
        
        return -1;
    }
};