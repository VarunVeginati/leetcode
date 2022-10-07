class Solution {
public:
    long long minimumHealth(vector<int>& damage, int armor) {
        int mx = damage[0];
        long long sum = damage[0];
        
        for(int i=1; i<damage.size(); i++) {
            sum += damage[i];
            mx = max(mx, damage[i]);
        }
        
        int mn = min(mx, armor);
        
        return sum-mn+1;
    }
};