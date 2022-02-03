class Solution {
public:
    
    int dfs(string s, int start, int end, int k) {
        if(end<k) return 0;
        vector<int> countMap = vector<int>(26, 0);
        
        for(int i=start; i<end; i++)
            countMap[s[i]-'a']++;
        
        for(int mid=start; mid<end; mid++) {
            if(countMap[s[mid]-'a']>=k) continue;
            int midNext = mid+1;
            while(midNext<end && countMap[s[midNext]-'a']<k)
                midNext++;
            return max(dfs(s, start, mid,k), dfs(s, midNext, end, k));
        }
        
        return (end-start);
    }
    
    int longestSubstring(string s, int k) {
        if(k==1) return s.length();
        
        return dfs(s, 0, s.length(), k);
    }
};