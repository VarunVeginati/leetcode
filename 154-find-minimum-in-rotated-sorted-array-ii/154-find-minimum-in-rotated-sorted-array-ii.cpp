class Solution {
public:
    int findMin(vector<int>& nums) {
        int mn = INT_MAX;
        
        for(int num: nums)
            mn = min(mn, num);
        
        return mn;
    }
};