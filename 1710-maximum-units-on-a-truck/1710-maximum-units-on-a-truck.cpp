class Solution {
public:
    int maximumUnits(vector<vector<int>>& boxTypes, int truckSize) {
        sort(boxTypes.begin(), boxTypes.end(), [](const vector<int> &a, 
                                                  const vector<int> &b) -> bool{
            return a[1]>b[1];
        });
        
        int res = 0;
        
        for(int i=0; i<boxTypes.size(); i++) {
            if(truckSize == 0) break;
            if(boxTypes[i][0]>truckSize) {
                res += (truckSize*boxTypes[i][1]);
                truckSize = 0;
            } else {
                truckSize -= boxTypes[i][0];
                res += (boxTypes[i][0] * boxTypes[i][1]);
            }
        }
        
        return res;
    }
};