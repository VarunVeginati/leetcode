class Solution {
public:
    
    static bool compare(pair<int,int> a, pair<int,int> b) {
        return a.second<b.second;
    }
    
    int findLeastNumOfUniqueInts(vector<int>& arr, int k) {
        map<int,int> m;
        for(int i=0; i<arr.size(); i++) m[arr[i]]++;
        vector<pair<int,int> > vec;
        
        for(auto it: m) {
            vec.push_back(make_pair(it.first, it.second));
        }
        
        sort(vec.begin(), vec.end(), compare);
        
        for(int i=0; i<vec.size(); i++) {
            if(vec[i].second > k)
                return vec.size()-i;
            else
                k = k-vec[i].second;
        }
        
        return 0;
    }
};