class Solution {
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        if(image[sr][sc]==color) return image;
        queue<pair<int,int>> q;
        q.push(make_pair(sr,sc));
        int m = image.size();
        int n = image[0].size();
        int col = image[sr][sc];
        
        image[sr][sc] = color;
        
        vector<pair<int,int>> directions = {
            make_pair(0,1), make_pair(0,-1),
            make_pair(1,0), make_pair(-1,0)
        };
        
        while(!q.empty()) {
            int ro = q.front().first;
            int co = q.front().second;
            q.pop();
            for(pair<int,int> direction : directions) {
                int r = direction.first + ro;
                int c = direction.second + co;
                
                if(r<0 || c<0 || r>=m || c>=n || image[r][c] != col) continue;
                
                image[r][c] = color;
                q.push(make_pair(r,c));
            }
        }
        
        return image;
    }
};