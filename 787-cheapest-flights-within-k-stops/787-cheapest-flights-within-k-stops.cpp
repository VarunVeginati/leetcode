// since the question asked about with atmost k stops we can't use Dijkstras algorithm. Hence we need to go with Bellman Ford algorithm.

class BellmanFord{
private:
	vector<vector<int>> dp;
	vector<vector<vector<int>>> edges;

public:
	BellmanFord(int k, int n, vector<vector<int>> graph) {
		dp = vector<vector<int>>(k+1, vector<int>(n, INT_MAX));
		edges = vector<vector<vector<int>>>(n);

		for(int i=0; i<graph.size(); i++) {
			edges[graph[i][1]].push_back({graph[i][0], graph[i][2]});
		}
	}

	int findMinCost(int source, int destination, int k, int n) {
		dp[0][source] = 0;

		for(int i=1; i<=k; i++) {
			for(int j=0; j<n; j++) {
				if(j==source) dp[i][j] = 0;
				else {
					vector<vector<int>> incomingEdges = edges[j];
					for(int k=0; k<incomingEdges.size(); k++) {
						int prev = dp[i-1][incomingEdges[k][0]];
						prev = prev == INT_MAX ? INT_MAX : prev+incomingEdges[k][1];
						dp[i][j] = min(dp[i][j], prev);
					}
				} 
			}
		}

		return dp[k][destination];
	}
};

class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        BellmanFord bfa(k+1, n, flights);
        
        int minCost = bfa.findMinCost(src,dst,k+1,n);

	    return  minCost == INT_MAX ? -1 : minCost;
    }
};