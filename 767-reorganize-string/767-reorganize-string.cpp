class Solution {
public:
    string reorganizeString(string s) {
        int l = s.length();
        vector<int> vec(26);
        string ans = "";
        
        for(char c: s) {
            vec[c-'a']++;
        }
        
        priority_queue<pair<int,char>> pq;
        
        for(char c='a'; c<='z'; c++) {
            if(vec[c-'a'] > 0)
                pq.push({vec[c-'a'], c});
        }
        
        while(pq.size()>1) {
            pair<int,char> p1 = pq.top();
            pq.pop();
            pair<int,char> p2 = pq.top();
            pq.pop();
            
            ans += p1.second;
            ans += p2.second;
            
            p1.first--;
            p2.first--;
            
            if(p1.first>0) pq.push(p1);
            if(p2.first>0) pq.push(p2);
        }
        
        if(pq.size()>0) {
            if(pq.top().first == 1){
                ans += pq.top().second;
            } else return "";
        }
        
        return ans;
    }
};