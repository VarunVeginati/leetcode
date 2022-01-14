class Solution {
public:
    void solve(vector<vector<char>>& board) {
        vector<pair<int,int>> directions = {
            make_pair(0,1),
            make_pair(0,-1),
            make_pair(1,0),
            make_pair(-1,0)
        };
        
        map<pair<int,int>, int> m;
        queue<pair<int,int>> q;
        int r = board.size();
        int c = board[0].size();
        
        for(int j=0; j<c; j++) {
            if(board[0][j]=='O') {
                m[make_pair(0,j)]++;
                q.push(make_pair(0,j));
            }
            if(board[r-1][j]=='O') {
                m[make_pair(r-1,j)]++;
                q.push(make_pair(r-1,j));
            }
        }
        
        for(int i=0; i<r; i++) {
            if(board[i][0]=='O') {
                m[make_pair(i,0)]++;
                q.push(make_pair(i,0));
            }
            if(board[i][c-1]=='O') {
                m[make_pair(i,c-1)]++;
                q.push(make_pair(i,c-1));
            }
        }
        
        while(!q.empty()) {
            int q_size = q.size();
            
            for(int i=0; i<q_size; i++) {
                for(pair<int,int> direction: directions) {
                    int row = q.front().first + direction.first;
                    int col = q.front().second + direction.second;
                    
                    if(row<0 || col<0 || row>=r || col>=c 
                       || m[make_pair(row,col)]>0
                       || board[row][col]=='X')
                        continue;
                    
                    m[make_pair(row,col)]++;
                    q.push(make_pair(row,col));
                }
                q.pop();
            }
        }
        
        for(int i=0; i<r; i++) {
            for(int j=0; j<c; j++) {
                if(board[i][j]=='O') {
                    if(m.find(make_pair(i,j)) == m.end())
                        board[i][j] = 'X';
                }
            }
        }
    }
};