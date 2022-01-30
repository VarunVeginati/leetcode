class Solution {
public:
    void gameOfLife(vector<vector<int>>& board) {
        vector<pair<int,int> > directions = {
            make_pair(-1,-1), make_pair(-1,0),
            make_pair(-1, 1), make_pair(0,-1),
            make_pair(0,1), make_pair(1,-1),
            make_pair(1,0), make_pair(1,1)
        };
        
        int m = board.size();
        int n = board[0].size();
        vector<vector<int>> neighbours(m, vector<int>(n, 0));
        
        for(int i=0; i<m; i++) {
            for(int j=0; j<n; j++) {
                int cnt = 0;
                for(pair<int,int> direction: directions) {
                    int r = i+direction.first;
                    int c = j+direction.second;
                    
                    if(r<0 || c<0 || r>=m || c>=n)
                        continue;
                    
                    if(board[r][c]==1) cnt++;
                }
                neighbours[i][j] = cnt;
            }
        }
        
        for(int i=0; i<m; i++) {
            for(int j=0; j<n; j++) {
                if(board[i][j] == 0 && neighbours[i][j]==3)
                    board[i][j]=1;
                else if(board[i][j] == 1) {
                    if(neighbours[i][j] < 2 || neighbours[i][j] > 3)
                        board[i][j] = 0;
                }
            }
        }
    }
};