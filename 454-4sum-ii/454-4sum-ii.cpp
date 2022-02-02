class Solution {
public:
    int fourSumCount(vector<int>& nums1, vector<int>& nums2, vector<int>& nums3, vector<int>& nums4) {
        int n = nums1.size();
        map<int,int> m;
        
        for(int i=0; i<n; i++) {
            for(int j=0; j<n; j++) {
                m[nums3[i]+nums4[j]]++;
            }
        }
        
        int cnt = 0;
        
        for(int i=0; i<n; i++) {
            for(int j=0; j<n; j++) {
                if(m[0-nums1[i]-nums2[j]] > 0) {
                    cnt += m[0-nums1[i]-nums2[j]];
                }
            }
        }
        
        return cnt;
    }
};