class Solution {
public:
    int minPartitions(string n) {
        int res = 0;
        
        for(int i=0; i<n.length(); i++) {
            res = max(res, (int)n[i] - 48);
        }
        
        return res;
    }
};