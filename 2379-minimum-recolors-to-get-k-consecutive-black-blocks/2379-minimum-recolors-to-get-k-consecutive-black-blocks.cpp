class Solution {
public:
    int minimumRecolors(string blocks, int k) {
        vector<int> vec;
        int cnt = 0;
        
        for(int i=0; i<blocks.length(); i++) {
            if(blocks[i]=='W') cnt++;
            vec.push_back(cnt);
        }
        
        int mn = vec[k-1];
        
        for(int i=k; i<blocks.length(); i++) {
            mn = min(mn, vec[i]-vec[i-k]);
        }
        
        return mn;
    }
};