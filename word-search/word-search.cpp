class Solution {
public:
    vector<pair<int,int>> directions = {
        make_pair(0,1),make_pair(0,-1),
        make_pair(1,0),make_pair(-1,0)
    };
    int m;
    int n;
    
    void bt(vector<vector<char>>& board, string word, int i, 
            int j, int k, vector<vector<int>> &visited, bool &flag) {
        if(k>=word.length()) {
            flag = true;
        }
        
        for(pair<int,int> direction: directions) {
            int r = i+direction.first;
            int c = j+direction.second;
            
            if(r<0 || c<0 || r>=m || c>=n || visited[r][c] == 1 
               ||board[r][c] != word[k]) continue;
            
            visited[r][c] = 1;
            bt(board, word, r, c, k+1, visited, flag);
            visited[r][c] = 0;
        }
    }
    
    bool exist(vector<vector<char>>& board, string word) {
        m = board.size();
        n = board[0].size();
        
        for(int i=0; i<m; i++) {
            for(int j=0; j<n; j++) {
                if(board[i][j] == word[0]) {
                    vector<vector<int>> visited(m, vector<int>(n, 0));
                    visited[i][j] = 1;
                    bool flag = false;
                    bt(board, word, i, j, 1, visited, flag);
                    if(flag) return true;
                }
            }
        }
        
        return false;
    }
};