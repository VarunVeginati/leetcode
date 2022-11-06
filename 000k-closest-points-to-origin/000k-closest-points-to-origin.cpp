class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        priority_queue<pair<int,int>> pq;
        
        for(int i=0; i<k; i++) {
            int dist = pow(points[i][0],2)+pow(points[i][1],2);
            pq.push(make_pair(dist, i));
        }
        
        for(int i=k; i<points.size(); i++) {
            int dist = pow(points[i][0],2)+pow(points[i][1],2);
            if(pq.top().first > dist) {
                pq.pop();
                pq.push(make_pair(dist, i));
            }
        }
        
        vector<vector<int>> res;
        
        while(!pq.empty()) {
            res.push_back(points[pq.top().second]);
            pq.pop();
        }
        
        return res;
    }
};