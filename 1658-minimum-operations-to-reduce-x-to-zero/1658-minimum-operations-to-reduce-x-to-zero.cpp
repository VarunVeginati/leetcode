class Solution {
    
public:
    int minOperations(vector<int>& nums, int x) {
        vector<int> vec1 = {nums[0]};
        vector<int> vec2 = {nums.back()};
        map<int, int> m1;
        map<int, int> m2;
        int n = nums.size();
        
        m1[nums[0]] = 0;
        m2[nums.back()] = 0;
        
        for(int i=1; i<n; i++) {
            vec1.push_back(nums[i]+vec1[i-1]);
            m1[vec1[i]]=i;
            vec2.push_back(nums[n-i-1]+vec2[i-1]);
            m2[vec2[i]]=i;
        }
        
        if(x>vec1.back() && x>vec2.back()) return -1;
        
        int mn = INT_MAX;
        
        for(int i=0; i<n; i++) {
            int target1 = x-vec1[i];
            int target2 = x-vec2[i];
            if(target1<0 && target2<0) break;
            if(m2.find(target1) != m2.end()) {
                mn = min(mn, i+m2[target1]+2);
            }
            if(m1.find(target2) != m1.end()) {
                mn = min(mn, i+m1[target2]+2);
            }
            else if(target1==0 || target2==0) {
                mn = min(mn, i+1);
            }
        }
        
//         for(int i=0; i<n; i++) {
//             int target = x-vec1[i];
//             if(target<0) break;
//             if(m2.find(target) != m2.end()) {
//                 mn = min(mn, i+m2[target]+2);
//             }
//             else if(target==0) {
//                 mn = min(mn, i+1);
//             }
//         }
        
//         for(int i=0; i<n; i++) {
//             int target = x-vec2[i];
//             if(target<0) break;
//             if(m1.find(target) != m1.end()) {
//                 mn = min(mn, i+m1[target]+2);
//             }
//             else if(target==0) {
//                 mn = min(mn, i+1);
//             }
//         }
        
        return mn==INT_MAX ? -1 : mn;
    }
};