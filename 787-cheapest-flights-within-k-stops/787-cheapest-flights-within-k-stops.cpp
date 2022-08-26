class BellmanFord{
private:
    vector<vector<int>> dp;
    vector<vector<pair<int,int> >> edges;
    
public:
    BellmanFord(int n, int k, vector<vector<int>>& flights) {
        dp = vector<vector<int>>(k+1, vector<int>(n, INT_MAX));
        edges = vector<vector<pair<int,int> >>(n);
        
        for(int i=0; i<flights.size(); i++) {
            edges[flights[i][1]].push_back(make_pair(flights[i][0], flights[i][2]));
        }
    }
    
    int processdp(int n, int l, int source, int dst) {
        dp[0][source] = 0;
        
        for(int i=1; i<=l; i++) {
            for(int j=0; j<n; j++) {
                if(j==source) dp[i][j]=0;
                else {
                    vector<pair<int,int> > incomingEdges = edges[j];
                    for(int k=0; k<incomingEdges.size(); k++) {
                        int prev = dp[i-1][incomingEdges[k].first];
                        prev = prev==INT_MAX?INT_MAX:prev+incomingEdges[k].second;
                        dp[i][j] = min(dp[i][j], prev);
                    }
                }
            }
        }
        
        return dp[l][dst];
    }
};

class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        BellmanFord bf = BellmanFord(n, k+1, flights);
        
        int minCost = bf.processdp(n, k+1, src, dst);
        
        return minCost == INT_MAX?-1:minCost;
    }
};