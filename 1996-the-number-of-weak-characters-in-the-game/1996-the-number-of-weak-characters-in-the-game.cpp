class Solution {
public:
    int numberOfWeakCharacters(vector<vector<int>>& properties) {
        sort(properties.begin(), properties.end(), [](const vector<int> &a, const vector<int> &b)->bool{
            if(a[0]==b[0]) return a[1]>b[1];
            return a[0]<b[0];
        });
        
        int maxDefense = 0;
        int cnt = 0;
        
        for(int i=properties.size()-1; i>=0; i--) {
            if(properties[i][1]<maxDefense) {
                cnt++;
            }
            maxDefense = max(maxDefense, properties[i][1]);
        }
        
        return cnt;
    }
};