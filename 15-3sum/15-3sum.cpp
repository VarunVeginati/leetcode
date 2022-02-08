class Solution {
public:
    vector<pair<int,int> > getTwoSum(vector<int> nums,int target) {
        int p1 = 0;
        int p2 = nums.size()-1;
        vector<pair<int,int> > out;
        while(p1<p2) {
            if(nums[p1]+nums[p2] == target) {
                out.push_back(make_pair(nums[p1],nums[p2]));
                p1++;
                p2--;
            }
            if(nums[p1]+nums[p2] > target) p2--;
            if(nums[p1]+nums[p2] < target) p1++;
        }
        return out;
    }
    
    vector<vector<int>> threeSum(vector<int>& nums) {
        if(nums.size() < 3) return {};
        vector<vector<int>> out;
        sort(nums.begin(),nums.end());
        map<vector<int>,int> vec_map;
        for(int i=0; i< nums.size()-2; i++) {
            int target = 0-nums[i];
            vector<pair<int,int> > vec = getTwoSum({nums.begin()+i+1, nums.end()}, target);
            if(vec.size() > 0) {
                for(int j=0; j<vec.size(); j++) {
                    vector<int> v = {nums[i], vec[j].first, vec[j].second};
                    if(vec_map[v] < 1) {
                    out.push_back(v);
                    vec_map[v]++;
                }
                }
            }
        }
        return out;
    }
};