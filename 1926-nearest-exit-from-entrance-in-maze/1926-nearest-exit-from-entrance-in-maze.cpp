class Solution {
public:
    int nearestExit(vector<vector<char>>& maze, vector<int>& entrance) {
        queue<pair<int,int>> q;
        q.push(make_pair(entrance[0], entrance[1]));
        int step = 0;
        maze[entrance[0]][entrance[1]]='+';
        vector<pair<int,int>> directions = {
            make_pair(0,1),make_pair(0,-1),
            make_pair(1,0),make_pair(-1,0),
        };
        int m = maze.size();
        int n = maze[0].size();
        
        while(!q.empty()) {
            step++;
            int size = q.size();
            
            for(int i=0; i<size; i++) {
                int row = q.front().first;
                int col = q.front().second;
                q.pop();
                
                for(pair<int,int> direction: directions) {
                    int r = row+direction.first;
                    int c = col+direction.second;
                    
                    if(r<0 || c<0 || r>=m || c>=n || maze[r][c]=='+') continue;
                    
                    if(r==0 || c==0 || r==m-1 || c==n-1) return step;
                    
                    maze[r][c]='+';
                    q.push(make_pair(r,c));
                }
            }
        }
        
        return -1;
    }
};