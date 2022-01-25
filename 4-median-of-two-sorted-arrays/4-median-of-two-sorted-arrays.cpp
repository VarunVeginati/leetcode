class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        vector<int> vec;
        
        int l1=0;
        int l2=0;
        
        while(vec.size()<(nums1.size()+nums2.size())) {
            if(l1<nums1.size() && l2<nums2.size()) {
                if(nums1[l1]<nums2[l2]) {
                    vec.push_back(nums1[l1]);
                    l1++;
                } else {
                    vec.push_back(nums2[l2]);
                    l2++;
                }
            } else if(l1>=nums1.size()) {
                vec.push_back(nums2[l2]);
                l2++;
            } else {
                vec.push_back(nums1[l1]);
                l1++;
            }
        }
        
        int n = vec.size();
        
        if(n%2 != 0) return (double) vec[n/2];
        else {
            return ((double) (vec[n/2]+vec[n/2-1])/2);
        }
    }
};