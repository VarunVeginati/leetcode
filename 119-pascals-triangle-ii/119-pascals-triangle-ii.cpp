class Solution {
public:
    vector<int> getRow(int rowIndex) {
        vector<int> res;
        if(rowIndex==0) return {1};
        if(rowIndex==1) return {1,1};
        
        vector<int> vec = {1,1};
        
        for(int i=2; i<=rowIndex; i++) {
            res.push_back(1);
            for(int j=1;j<vec.size(); j++) {
                res.push_back(vec[j]+vec[j-1]);
            }
            res.push_back(1);
            
            vec = res;
            res = {};
        }
        
        return vec;
    }
};