class Solution {
public:
    int findMaxLength(vector<int>& nums) {
        int cnt = 0;
        
        map<int,int> m;
        m[0] = -1;
        int mx = 0;
        
        for(int i=0; i<nums.size(); i++) {
            if(nums[i]==0) cnt--;
            else cnt++;
            
            if(m.find(cnt) != m.end())
                mx = max(mx, i-m[cnt]);
            else
                m[cnt] = i;
        }
        
        return mx;
    }
};