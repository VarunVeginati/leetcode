class Solution {
public:
    int totalFruit(vector<int>& fruits) {
        int ans = 0;
        int a = fruits[0];
        int b = -1;
        int lo = 0;
        int hi = -1;
        pair<int,int> m = make_pair(lo,-1);
        
        for(int i=1; i<fruits.size(); i++) {
            if(fruits[i]!= a) {
                b = fruits[i];
                m.second = i;
                hi = i;
                break;
            }
            m.first = i;
        }
        
        if(b==-1) return fruits.size();
        
        ans = hi-lo+1;
        
        for(int i=hi+1; i<fruits.size(); i++) {
            if(fruits[i] != a && fruits[i] != b) {
                if(m.first > m.second) {
                    lo = m.second+1;
                    b = fruits[i];
                    m.second = i;
                } else {
                    lo = m.first+1;
                    a = fruits[i];
                    m.first = i;
                }
            } else if(fruits[i]==a) {
                m.first = i;
            } else if(fruits[i]==b) {
                m.second = i;
            }
            
            ans = max(ans, i-lo+1);
        }
        
        return ans;
    }
};