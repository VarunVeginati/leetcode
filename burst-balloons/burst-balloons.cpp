class Solution {
public:
//     map<pair<int,int>, int> hashmap;
//     vector<int> nums;
    
//     int dp(int left, int right) {
//         if(right-left<0) return 0;
        
//         if(hashmap[make_pair(left,right)] != 0) return hashmap[make_pair(left,right)];
        
//         int mx = INT_MIN;
        
//         for(int i=left; i<=right; i++) {
//             int t = nums[left-1]*nums[i]*nums[right+1];
//             mx = max(t+dp(left,i-1)+dp(i+1,right), mx);
//         }
        
//         hashmap[make_pair(left, right)] = mx;
        
//         return hashmap[make_pair(left, right)];
//     }
    
    int maxCoins(vector<int>& nums) {
        // nums = numbers;
        nums.insert(nums.begin(),1);
        nums.push_back(1);
        vector<vector<int>> dp(nums.size(), vector<int>(nums.size(),0));
        
        for(int left=nums.size()-2; left>=1; left--) {
            for(int right=left; right<=nums.size()-2; right++) {
                for(int i=left; i<=right; i++) {
                    int t = nums[left-1]*nums[i]*nums[right+1];
                    dp[left][right] = 
                        max(t+dp[left][i-1]+dp[i+1][right],
                            dp[left][right]);
                }
            }
        }
        return dp[1][nums.size()-2];
    }
};