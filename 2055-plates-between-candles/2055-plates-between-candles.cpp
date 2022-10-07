class Solution {
public:
    int lowerBound(vector<int> &vec, int l, int r, int tar) {
        if(l<=r) {
            int mid = l + (r-l)/2;
            
            if(vec[mid]<=tar) return lowerBound(vec, mid+1, r, tar);
            else return lowerBound(vec, l, mid-1, tar);
        }
        
        return max(r, 0);
    }
    
    int upperBound(vector<int> &vec, int l, int r, int tar) {
        if(l<=r) {
            int mid = l + (r-l)/2;
            
            if(vec[mid]<tar) return upperBound(vec, mid+1, r, tar);
            else return upperBound(vec, l, mid-1, tar);
        }

        return min(l, (int) vec.size()-1);
    }
    
    vector<int> platesBetweenCandles(string s, vector<vector<int>>& queries) {
        vector<int> vec;
        vector<int> vec1;
        bool flag = false;
        int sum = 0;
        
        for(int i=0; i<s.length(); i++) {
            if(flag && s[i]=='*') sum++;
            else if(!flag && s[i]=='|') {
                flag = true;
                vec.push_back(i);
                vec1.push_back(0);
            }
            else if(flag && s[i]=='|') {
                vec.push_back(i);
                vec1.push_back(sum);
            }
        }
        
        if(vec.size() <= 1) return vector<int>(queries.size(), 0);
        
        vector<int> res;
        
        for(int i=0; i<queries.size(); i++) {
            int curr = vec1[lowerBound(vec, 0, vec.size()-1, queries[i][1])] - vec1[upperBound(vec, 0, vec.size()-1, queries[i][0])];
            res.push_back(max(curr, 0));
        }
        
        return res;
    }
};