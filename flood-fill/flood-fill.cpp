class Solution {
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int newColor) {
        int m = image.size();
        int n = image[0].size();
        vector<pair<int,int> > directions = {
            make_pair(0,1),
            make_pair(0,-1),
            make_pair(1,0),
            make_pair(-1,0)
        };
        int starting_pixel = image[sr][sc];
        queue<pair<int,int> > q;
        q.push(make_pair(sr,sc));
        vector<vector<int>> visited(m, vector<int>(n,0));
        visited[sr][sc] = 1;
        
        while(!q.empty()) {
            int q_size = q.size();
            
            for(int i=0; i<q_size; i++) {
                int row = q.front().first;
                int col = q.front().second;
                image[row][col] = newColor;
                for(pair<int,int> direction: directions) {
                    int r = row+direction.first;
                    int c = col+direction.second;
                    
                    if(r<0 || c<0 || r>=m || c>=n || visited[r][c]==1 || image[r][c]!=starting_pixel)
                        continue;
                    
                    visited[r][c]=1;
                    q.push(make_pair(r,c));
                }
                q.pop();
            }
        }
        
        return image;
    }
};