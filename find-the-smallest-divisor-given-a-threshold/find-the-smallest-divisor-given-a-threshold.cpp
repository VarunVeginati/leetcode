class Solution {
public:
    int divide(int a, int b) {
        return a%b==0?(a/b):(a/b)+1;
    }
    
    
    
    int smallestDivisor(vector<int>& nums, int threshold) {
        sort(nums.begin(), nums.end());
        
        // for(int i=1; i<=nums.back(); i++) {
        //     int sum = 0;
        //     for(int j=0; j<nums.size(); j++) {
        //         sum += divide(nums[j],i);
        //     }
        //     if(sum<=threshold) return i;
        // }
        
        int left=1;
        int right=nums.back();
        
        while(left<right) {
            int sum = 0;
            int mid = (left+right)/2;
            for(int j=0; j<nums.size(); j++) {
                sum += divide(nums[j],mid);
            }
            if(sum<=threshold) right=mid;
            else left=mid+1;
        }
        
        return left;
    }
};