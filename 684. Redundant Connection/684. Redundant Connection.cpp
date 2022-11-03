#include <vector>
#include <map>
class Solution {
public:
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        map<int,vector<int>> adj;
        for (auto edge : edges) {
            if (targetReached(adj, edge[0], edge[1])) return edge;
            
            adj[edge[0]].push_back(edge[1]);
            adj[edge[1]].push_back(edge[0]);
            
        }
        return edges[0];
    }
    
    bool targetReached(map<int,vector<int>>& adj, int begin, int target) {
        stack<int> stk;
        set<int> visited;
        int pop;
        stk.push(begin);
        while (stk.size()) {
            pop = stk.top(), stk.pop();
            if (visited.count(pop)) continue;
            visited.insert(pop);
            if (pop == target) return true; 
            for (int next : adj[pop]) stk.push(next);
        }
        return false;
    }
};