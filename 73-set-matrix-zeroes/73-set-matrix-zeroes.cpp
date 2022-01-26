class Solution {
public:
    
    void set_col_row_zeros(vector<vector<int>>& matrix, int i, int j) {
        int r = i-1;
        while(r>=0) {
            matrix[r][j]=0;
            r--;
        }
        r = i+1;
        while(r<matrix.size()) {
            matrix[r][j]=0;
            r++;
        }
        int c = j-1;
        while(c>=0) {
            matrix[i][c]=0;
            c--;
        }
        c = j+1;
        while(c<matrix[0].size()) {
            matrix[i][c]=0;
            c++;
        }
    }
    
    void setZeroes(vector<vector<int>>& matrix) {
        vector<pair<int,int>> vec;
        for(int i=0; i<matrix.size(); i++) {
            for(int j=0; j<matrix[0].size(); j++) {
                if(matrix[i][j]==0) {
                    vec.push_back(make_pair(i,j));
                }
            }
        }
        
        for(int i=0; i<vec.size(); i++) {
            set_col_row_zeros(matrix, vec[i].first, vec[i].second);
        }
    }
};