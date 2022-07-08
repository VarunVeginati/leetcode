class Solution {
private:
    vector<int> arr;
    vector<int> prefixSum;
    vector<vector<int>> memo;
    
    int getSum(int l, int r) {
        if(l==0) return prefixSum[r];
        else {
            return prefixSum[r]-prefixSum[l-1];
        }
    }
    
    int dp(int l, int r) {
        if(l==r) {
            return 0;
        }
        
        if(memo[l][r] != INT_MAX) return memo[l][r];
        
        int mx = 0;
        
        for(int i=l; i<r; i++) {
            int a = getSum(l,i);
            int b = getSum(i+1,r);
            
            if(a<b) {
                mx = max(mx, a+dp(l,i));
            } else if(b<a) {
                mx = max(mx, b+dp(i+1,r));
            } else {
                mx = max(mx, a+dp(l,i));
                mx = max(mx, b+dp(i+1,r));
            }
        }
        
        memo[l][r] = mx;
        
        return mx;
    }
    
public:
    int stoneGameV(vector<int>& stoneValue) {
        arr = stoneValue;
        int n = stoneValue.size();
        memo = vector<vector<int>>(n, vector<int>(n, INT_MAX));
        prefixSum.push_back(stoneValue[0]);
        
        for(int i=1; i<n; i++) {
            prefixSum.push_back(stoneValue[i]+prefixSum.back());
        }
        
//         for(int i=0; i<n; i++) {
//             cout << prefixSum[i] << endl;
//         }
        
        return dp(0, n-1);
    }
};