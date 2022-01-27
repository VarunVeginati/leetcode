class Solution {
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
        if(nums2.size() > nums1.size()) {
            return intersect(nums2, nums1);
        }
        
        map<int,int> m;
        
        for(int i=0; i<nums2.size(); i++) {
            m[nums2[i]]++;
        }
        
        vector<int> out;
        
        for(int i=0; i<nums1.size(); i++) {
            if(m[nums1[i]] > 0) {
                out.push_back(nums1[i]);
                m[nums1[i]]--;
            }
        }
        
        return out;
    }
};