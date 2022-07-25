class Solution {
public:
    int start = -1;
    int end = -1;
    vector<int> vec;
    int tar;
    
    void bS(int left, int right) {
        if(left<=right) {
            int mid = left+((right-left)/2);
            
            if(vec[mid]==tar) {
                if(start == -1) {
                    if(mid==0 || vec[mid-1]<tar) start = mid;
                    else {
                        bS(left, mid-1);
                    }
                }
                if(end == -1) {
                    if(mid==vec.size()-1 || vec[mid+1]>tar) end = mid;
                    else {
                        bS(mid+1, right);
                    }
                }
            } else if(vec[mid]>tar) {
                bS(left, mid-1);
            } else if(vec[mid]<tar) {
                bS(mid+1, right);
            }
         }
    }
    
    vector<int> searchRange(vector<int>& nums, int target) {
        vec = nums;
        tar = target;
        bS(0, nums.size()-1);
        
        return {start, end};
    }
};