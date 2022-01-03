class Solution {
public:
    int findJudge(int n, vector<vector<int>>& trust) {
        map<int, set<int>> hashmap;
        
        for(int i=0; i<trust.size(); i++) {
            hashmap[trust[i][0]].insert(trust[i][1]);
        }
        
        for(int i=1; i<=n; i++) {
            if(hashmap[i].size()==0) {
                bool flag = true;
                for(int j=1; j<=n; j++) {
                    set<int> s = hashmap[j];
                    if(i!=j && s.find(i) == s.end()) {
                        flag = false;
                        break;
                    }
                }
                if(flag) return i;
            }
        }
        
        return -1;
    }
};