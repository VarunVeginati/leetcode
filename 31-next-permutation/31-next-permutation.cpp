class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int a = -1;
        int b = -1;
        
        for(int i=nums.size()-1; i>=0; i--) {
            for(int j=i-1; j>=0; j--) {
                if(nums[j] < nums[i] && j>b) {
                    a = i;
                    b = j;
                    break;
                }
            }
            // if(index != -1) break;
        }
        
        if(a != -1 && b!=-1) {
            nums[a] = nums[a]^nums[b];
            nums[b] = nums[a]^nums[b];
            nums[a] = nums[a]^nums[b];
        }
        
        b++;
        sort(nums.begin()+b, nums.end());
    }
};