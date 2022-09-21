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
        
        for(int i=0; i<prefixSum.size(); i++)
            if(target < prefixSum[i])
                return i;
        
        return prefixSum.size()-1;
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(w);
 * int param_1 = obj->pickIndex();
 */