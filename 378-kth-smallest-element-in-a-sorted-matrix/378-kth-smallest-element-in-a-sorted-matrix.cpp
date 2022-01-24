class Solution {
public:
    int kthSmallest(vector<vector<int>>& matrix, int k) {
        int m = 100000;
        int n = 100000;
        int cnt=0;
        priority_queue<int> pq;
        
        for(int i=0; i<matrix.size(); i++) {
            for(int j=0; j<matrix[0].size(); j++) {
                if(cnt<k) {
                    cnt++;
                    pq.push(matrix[i][j]);
                } else {
                    m = i;
                    n = j;
                    i = matrix.size();
                    j = matrix[0].size();
                }
            }
        }
        
        // cout << m << "," << n;
        
        for(int j=n; j<matrix[0].size(); j++) {
                if(pq.top() > matrix[m][j]) {
                    pq.pop();
                    pq.push(matrix[m][j]);
                }
            }
        
        for(int i=m+1; i<matrix.size(); i++) {
            for(int j=0; j<matrix[0].size(); j++) {
                if(pq.top() > matrix[i][j]) {
                    pq.pop();
                    pq.push(matrix[i][j]);
                }
            }
        }
        
        return pq.top();
    }
};