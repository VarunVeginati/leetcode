class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        map<int,int> m;
        
        for(int i=0; i<numbers.size(); i++) {
            int j = target - numbers[i];
            
            if(m.find(j) != m.end()) return {m[j]+1, i+1};
            
            m[numbers[i]] = i;
        }
        
        return {};
    }
};