class Solution {
public:
    int furthestBuilding(vector<int>& heights, int bricks, int ladders) {
        priority_queue<int, vector<int>, greater<int>> pq;
        
        int i=0;
        
        while(ladders>0 && i<heights.size()-1) {
            if(heights[i+1]>heights[i]) {
                pq.push(heights[i+1]-heights[i]);
                ladders--;
            }
            i++;
        }
        
        while(i<heights.size()-1) {
            int a = heights[i+1]-heights[i];
            if(heights[i+1]>heights[i]) {
                if(pq.empty() && bricks>=a)
                    bricks -= a;
                else if(!pq.empty() && a>pq.top() && bricks>=pq.top()) {
                    bricks -= pq.top();
                    pq.pop();
                    pq.push(a);
                } else if(a>bricks) {
                    break;
                } else {
                    bricks -= a;
                }
            }
            i++;
        }
        
        return i;
    }
};