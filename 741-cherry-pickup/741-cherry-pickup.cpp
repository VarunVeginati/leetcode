class Solution {
public:
    vector<vector<int>> vec;
    vector<vector<vector<int>>> memo;
    int r;
    int c;
    
    vector<pair<int,int>> directions = {
        make_pair(0,1),
        make_pair(1,0)
    };
    
    bool is_invalid(int r1, int c1, int r2, int c2) {
        return (r1<0 || r2<0 || c1<0 || c2<0 ||
                r1>=r || r2>=r || c1>=c || c2>=c);
    }
    
    int dp(int r1, int c1, int c2) {
        int r2 = r1+c1-c2;
        if(r1==r2 && c1==c2 && r1==r-1 && c1==c-1) {
            return vec[r1][c1];
        }
        
        if(memo[r1][c1][c2] == -2) {
            int mx = -9999;
            for(int i=0; i<2; i++){
                for(int j=0; j<2; j++) {
                    int row1 = r1+directions[i].first;
                    int col1 = c1+directions[i].second;
                    int row2 = r2+directions[j].first;
                    int col2 = c2+directions[j].second;
                    
                    if(is_invalid(row1, col1, row2, col2))
                        continue;
                    
                    int a;
                    if(r1==r2 && c1==c2) {
                        a = vec[r1][c1] == -1? -9999: vec[r1][c1];
                    }
                    else {
                        int d = vec[r1][c1] == -1? -9999: vec[r1][c1];
                        int e = vec[r2][c2] == -1? -9999: vec[r2][c2];
                        a = d+e;
                    }
                    a += dp(row1, col1, col2);
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
        memo = vector<vector<vector<int>>>(r, vector<vector<int>>(c, vector<int>(c,-2)));
        
        return max(0,dp(0, 0, 0));
    }
};