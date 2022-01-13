class Solution {
public:
    // static bool compare(vector<int> a, vector<int> b) {
    //     return a[1]<b[1];
    // }
    
    int findMinArrowShots(vector<vector<int>>& points) {
        sort(points.begin(), points.end(), [](const vector<int> &a, const vector<int> &b) {   
            return (a[1]<b[1]);
        });
        int cnt = 0;
        int i;
        
        for(i=0; i<points.size(); i++) {
            int min = points[i][1];
            while(i<points.size()-1 && points[i+1][0]<=min)
                i++;
            cnt++;
        }
        
        if(i<points.size()) cnt++;
        
        return cnt;
    }
};