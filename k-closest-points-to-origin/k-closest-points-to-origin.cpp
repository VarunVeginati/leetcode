class Solution {
public:
    int sum_of_squares(int a, int b) {
        return (a*a)+(b*b);
    }
    
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        priority_queue<pair<int,int> > pq;
        
        for(int i=0; i<k; i++)
            pq.push(make_pair(sum_of_squares(points[i][0], points[i][1]), i));
        
        for(int i=k; i<points.size(); i++) {
            int a = sum_of_squares(points[i][0], points[i][1]);
            if(pq.top().first > a) {
                pq.pop();
                pq.push(make_pair(a, i));
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