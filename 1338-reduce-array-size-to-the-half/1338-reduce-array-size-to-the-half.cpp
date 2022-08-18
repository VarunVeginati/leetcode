class Solution {
public:
    int minSetSize(vector<int>& arr) {
        int n = arr.size();
        map<int,int> m;
        
        for(int i=0; i<arr.size(); i++) {
            m[arr[i]]++;
        }
        
        priority_queue<pair<int,int> > pq;
        
        for(auto it: m) {
            pq.push(make_pair(it.second, it.first));
        }
        
        int a = 0;
        int b = n%2==0?n/2:((n/2)+1);
        int res = 0;
        
        while(a<b) {
            res++;
            a+=pq.top().first;
            pq.pop();
        }
        
        return res;
    }
};