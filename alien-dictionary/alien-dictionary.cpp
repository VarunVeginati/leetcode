class TopologicalOrder{
private:
    vector<vector<char>> edges;
    map<int,int> indegree;
    string order = "";
    queue<int> q;
    bool isPossible = true;
    
public:
    TopologicalOrder(vector<vector<char>> graph, map<int,int> indeg) {
        edges = graph;
        indegree = indeg;
    }
    
    void setOrder() {
        for(int i=0; i<26; i++) {
            if(indegree.find(i)!=indegree.end() && indegree[i]==0) {
                q.push(i);
            }
        }
        
        while(!q.empty() && isPossible) {
            int curr = q.front();
            q.pop();
            order += (char) (curr+97);
            
            vector<char> adjacentNodes = edges[curr];
            
            for(int i=0; i<adjacentNodes.size(); i++) {
                if(indegree[adjacentNodes[i]-'a']==0) {
                    isPossible = false;
                    break;
                }
                indegree[adjacentNodes[i]-'a']--;
                if(indegree[adjacentNodes[i]-'a']==0)
                    q.push(adjacentNodes[i]-'a');
            }
        }
    }
    
    string getOrder() {
        for(int i=0; i<26; i++) {
            if(indegree[i] != 0) {
                isPossible = false;
                break;
            }
        }
        
        return isPossible ? order:"";
    }
};

class Solution {
public:
    string alienOrder(vector<string>& words) {
        vector<vector<char>> graph(26);
        map<int,int> indegree;
        
        for(int k=0; k<words[0].length(); k++) {
            if(indegree.find(words[0][k]-'a') == indegree.end())
                indegree[words[0][k]-'a'] = 0;
        }
        
        for(int i=0; i<words.size()-1; i++) {
            string a = words[i];
            string b = words[i+1];
            
            for(int k=0; k<a.length(); k++) {
                if(indegree.find(a[k]-'a') == indegree.end())
                    indegree[a[k]-'a'] = 0;
            }
            
            for(int k=0; k<b.length(); k++) {
                if(indegree.find(b[k]-'a') == indegree.end())
                    indegree[b[k]-'a'] = 0;
            }
            
            for(int j=0; j<a.length(); j++) {
                if(j>=b.length()) {
                    return "";
                }
                if(a[j]!=b[j]) {
                    graph[a[j]-'a'].push_back(b[j]);
                    indegree[b[j]-'a']++;
                    break;
                }
            }
        }
        
        TopologicalOrder to = TopologicalOrder(graph, indegree);
        to.setOrder();
        return to.getOrder();
    }
};