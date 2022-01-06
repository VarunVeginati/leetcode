class Solution {
public:
    bool carPooling(vector<vector<int>>& trips, int capacity) {
        vector<int> vec(1001, 0);
        
        for(int i=0; i<trips.size(); i++) {
            vec[trips[i][1]] += trips[i][0];
            vec[trips[i][2]] -= trips[i][0];
        }
        
        int usedCapacity = 0;
        
        for(int i=0; i<vec.size(); i++) {
            usedCapacity += vec[i];
            if(usedCapacity>capacity) {
                return false;
            }
        }
        
        return true;
    }
};