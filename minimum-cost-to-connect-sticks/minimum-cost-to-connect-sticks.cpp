class Solution {
public:
    int connectSticks(vector<int>& sticks) {
        priority_queue<int, vector<int>, greater<int>> pq;
        
        for(int i=0; i<sticks.size(); i++)
            pq.push(sticks[i]);
        
        int cnt = 0;
        
        while(pq.size() > 1) {
            int a = pq.top();
            pq.pop();
            int b = pq.top();
            pq.pop();
            cnt += a+b;
            pq.push(a+b);
        }
        
        return cnt;
    }
};