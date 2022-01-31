class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        int m = matrix.size();
        if(m==0) return;
        
        for(int i=0; i<m/2; i++) {   
            vector<pair<int,int> > corners = {
                make_pair(i,i), make_pair(i,m-1-i),
                make_pair(m-1-i,m-1-i), make_pair(m-1-i,i)
            };
            
            for(int j=0; j<m-1-(i*2); j++) {
                int temp = INT_MIN;
                int x;
                int y;
                for(int k=0; k<4; k++) {
                    int a;
                    int b;
                    if(k==0) {
                        a = corners[k].first;
                        b = corners[k].second + j;
                    } else if(k==1) {
                        a = corners[k].first+j;
                        b = corners[k].second;
                    } else if(k==2) {
                        a = corners[k].first;
                        b = corners[k].second - j;
                    } else if(k==3) {
                        a = corners[k].first-j;
                        b = corners[k].second;
                    }

                    if(temp == INT_MIN) {
                        temp = matrix[a][b];
                        x = a;
                        y = b;
                    }
                    else {
                        int curr = matrix[a][b];
                        matrix[a][b] = temp;
                        temp = curr;
                    }
                }
                matrix[x][y] = temp;
            }
        }
    }
};