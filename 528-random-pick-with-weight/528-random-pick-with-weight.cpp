class Solution {
private:
    vector<int> prefixSum;

public:
    Solution(vector<int>& w) {
        prefixSum.push_back(w[0]);
        for(int i=1; i<w.size(); i++) {
            prefixSum.push_back(w[i]+prefixSum[i-1]);
        }
    }
    
    int pickIndex() {
        float randNum = (float) rand()/RAND_MAX;
        float target = randNum * prefixSum.back();
        
        // binary search
        int l=0;
        int r = prefixSum.size()-1;
        
        while(l<=r) {
            int mid = l + (r-l)/2;
            
            if(target < prefixSum[mid])  r = mid-1;
            else l = mid+1;
        }
        
        return l;
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(w);
 * int param_1 = obj->pickIndex();
 */