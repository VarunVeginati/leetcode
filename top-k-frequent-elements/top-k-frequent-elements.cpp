class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        map<int,int> m;
        
        for(int i=0; i<nums.size(); i++)
            m[nums[i]]++;
        
        priority_queue<pair<int,int> > pq;
        
        for(auto it: m)
            pq.push(make_pair(it.second, it.first));
        
        vector<int> vec;
        
        for(int i=1; i<=k; i++) {
            vec.push_back(pq.top().second);
            pq.pop();
        }
        
        return vec;
    }
};