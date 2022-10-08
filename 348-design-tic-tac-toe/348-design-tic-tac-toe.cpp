class TicTacToe {
private:
    vector<vector<int>> row_vec;
    vector<vector<int>> col_vec;
    vector<vector<int>> diag;

public:
    TicTacToe(int n) {
        row_vec = vector<vector<int>>(n, vector<int>(3,0));
        col_vec = vector<vector<int>>(n, vector<int>(3,0));
        diag = vector<vector<int>>(2, vector<int>(3,0));
    }
    
    int move(int row, int col, int player) {
        row_vec[row][player]++;
        col_vec[col][player]++;

        if(row==col && row==row_vec.size()-col-1) {
            diag[0][player]++;
            diag[1][player]++;
        } else if(row == col) {
            diag[0][player]++;
        } else if(row==row_vec.size()-col-1) {
            diag[1][player]++;
        }

        if(row_vec[row][player] == row_vec.size() || col_vec[col][player] == row_vec.size()) return player;
        else if(diag[0][player] == row_vec.size() || diag[1][player] == row_vec.size()) return player;
        else return 0;
    }
};

/**
 * Your TicTacToe object will be instantiated and called as such:
 * TicTacToe* obj = new TicTacToe(n);
 * int param_1 = obj->move(row,col,player);
 */