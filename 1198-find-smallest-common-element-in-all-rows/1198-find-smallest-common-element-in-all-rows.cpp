class Solution {
public:
    int bS(vector<int> &vec, int l, int r, int target) {
        if(l<=r) {
            int mid = l + ((r-l)/2);
            
            if(vec[mid] == target) return mid;
            
            if(vec[mid]<target) return bS(vec, mid+1, r, target);
            return bS(vec, l, mid-1, target);
        }
        
        return -1;
    }
    
    int smallestCommonElement(vector<vector<int>>& mat) {
        int m = mat.size();
        int n = mat[0].size();
        
        for(int i=0; i<n; i++) {
            bool flag = true;
            for(int j=1; j<m; j++) {
                if(bS(mat[j], 0, n-1, mat[0][i]) == -1) {
                    flag = false;
                    break;
                }
            }
            if(flag) return mat[0][i];
        }
        
        return -1;
    }
};