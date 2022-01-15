class Solution {
public:
    int minJumps(vector<int>& arr) {
        int n = arr.size();
        vector<int> visited(n, 0);
        map<int, vector<int>> m;
        
        for(int i=0; i<n; i++)
            m[arr[i]].push_back(i);
        
        queue<int> q;
        q.push(0);
        int cnt = 0;
        
        visited[0]=1;
        
        while(!q.empty()) {
            int q_size = q.size();
            
            for(int j=0; j<q_size; j++) {
                int i = q.front();
                if(i>=n-1) return cnt;
                q.pop();
                
                for(int ele: m[arr[i]]) {
                    if(visited[ele] == 0) {
                        visited[ele] = 1;
                        q.push(ele);
                    }
                }
                
                m.erase(arr[i]);
                
                if(i+1<n && visited[i+1]==0) {
                    visited[i+1] = 1;
                    q.push(i+1);
                }
                if(i-1>0 && visited[i-1]==0) {
                    visited[i-1] = 1;
                    q.push(i-1);
                }
            }
            
            cnt++;
        }
        
        return -1;
    }
};