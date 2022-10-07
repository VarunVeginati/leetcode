class Solution {
public:
    void permute(vector<string> &vec, vector<string> res, int start, set<vector<string>> &st) {
        if(vec.size()<3) return;
        if(res.size()==3) {
            st.insert(res);
            return;
        }
        
        for(int i=start; i<vec.size(); i++) {
            res.push_back(vec[i]);
            permute(vec, res, i+1, st);
            res.pop_back();
        }
    }
    
    
    
    vector<string> mostVisitedPattern(vector<string>& username, vector<int>& timestamp, vector<string>& website) {
        map<string, vector<string>> visitmap;
        
        vector<pair<int, pair<string,string> >> comb;
        
        for(int i=0; i<username.size(); i++) {
            comb.push_back(make_pair(timestamp[i], make_pair(username[i], website[i])));
        }
        
        sort(comb.begin(), comb.end());
        
        for(int i=0; i<comb.size(); i++) {
            visitmap[comb[i].second.first].push_back(comb[i].second.second);
        }
        
        map<vector<string>, int> m;
        int mx = 0;
        
        for(auto it: visitmap) {
            set<vector<string>> st;
            permute(it.second, {}, 0, st);
            
            for(auto itr: st) {
                m[itr]++;
                mx = max(mx, m[itr]);
            }
        }
        
        vector<vector<string>> vec;
        
        for(auto it: m) {
            if(it.second==mx) vec.push_back(it.first);
        }
        
        sort(vec.begin(), vec.end());
        
        if(vec.size()==0) return {};
        
        return vec[0];
    }
};