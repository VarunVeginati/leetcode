class Solution {
public:
    int numPairsDivisibleBy60(vector<int>& time) {
        int cnt = 0;
        map<int,int> hashmap;
        
        for(int i=0; i<time.size(); i++) {
            if(hashmap[60-time[i]%60] > 0)
                cnt += hashmap[60-time[i]%60];
            
            if(time[i]%60 == 0) hashmap[60]++;
            else hashmap[time[i]%60]++;
        }
        
        return cnt;
    }
};