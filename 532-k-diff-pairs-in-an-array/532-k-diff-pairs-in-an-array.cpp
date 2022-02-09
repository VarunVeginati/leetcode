class Solution {
public:
    
    // int get_for_zero(map<int,int> m, vector<int> nums) {
    //     for(int i=0; i<)
    // }
    
    int findPairs(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());
        int cnt = 0;
        map<int,int> m;
        
        for(int i=0; i<nums.size(); i++)
            m[nums[i]]++;
        
        // if(m.find(nums[0]+k) != m.end()) cnt++;
        
        for(int i=0; i<nums.size(); i++) {
            if(i!=0 && nums[i]==nums[i-1])
                continue;
            
            if(k==0) {
                if(m[nums[i]]>1) cnt++;
            }
            else if(m.find(nums[i]+k) != m.end()) cnt++;
        }
        
        return cnt;
    }
};