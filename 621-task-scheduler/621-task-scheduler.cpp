class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        vector<int> vec(26, 0);
        
        for(int i=0; i<tasks.size(); i++) {
            vec[tasks[i]-'A']++;
        }
        
        int mx = INT_MIN;
        
        for(int i=0; i<vec.size(); i++) {
            mx = max(mx, vec[i]);
        }
        
        int n_max = 0;
        
        for(int i=0; i<vec.size(); i++) {
            if(mx==vec[i]) n_max++;
        }
        
        int total = ((mx-1)*(n+1))+n_max;
        int size = tasks.size();
        
        return max(size, total);
    }
};