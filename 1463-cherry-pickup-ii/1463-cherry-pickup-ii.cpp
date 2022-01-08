class Solution {
public:
    vector<vector<int>> vec;
    vector<vector<vector<int>>> memo;
    int r;
    int c;
    
    vector<int> direction = {-1,0,1};
    
    int dp(int r1, int c1, int c2) {
        if(r1>=r-1) {
            return vec[r1][c1]+vec[r1][c2];
        }
        
        if(memo[r1][c1][c2] == -1) {
            int mx = 0;
            for(int i=0; i<3; i++){
                for(int j=0; j<3; j++) {
                    int col1 = c1+direction[i];
                    int col2 = c2+direction[j];
                    
                    if(col1<0 || col2<0 || col1>=c || col2>=c || col1==col2)
                        continue;
                    
                    int a = vec[r1][c1]+vec[r1][c2] +dp(r1+1, col1, col2);
                    mx = max(mx, a);
                }
            }
            memo[r1][c1][c2] = mx;
        }
        
        return memo[r1][c1][c2];
    }
    
    int cherryPickup(vector<vector<int>>& grid) {
        vec = grid;
        r = grid.size();
        c = grid[0].size();
        memo = vector<vector<vector<int>>>(r, vector<vector<int>>(c, vector<int>(c,-1)));
        
        return dp(0, 0, c-1);
    }
};