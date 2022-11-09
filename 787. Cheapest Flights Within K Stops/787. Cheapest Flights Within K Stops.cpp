class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        // set the routes first
        // [{{dst, cost}, {dst, cost}...}, {...}]
        vector<vector<pair<int,int>>> adj(n, vector<pair<int,int>>{});
        for (auto edge : flights) adj[edge[0]].push_back({edge[1], edge[2]});
        
        // do a dfs, tracking the cheapest price once reached; track currprice, currk
        // {loc, currprice, currk}
        // also track explored. If already explored no need to proceed (it's looped and is only more expensive)
        int res = INT_MAX; 
        stack<vector<int>> stk;
        stk.push({src, 0, k + 1});
        while (stk.size()) {
            vector<int> popVals = stk.top();
            stk.pop();
            // checks the destination having reached or the k running out 
            if (popVals[0] == dst) { res = min(res, popVals[1]); continue; }
            if (popVals[2] == 0) continue; 
            // explore next
            for (pair<int,int>& vec : adj[popVals[0]]) {
                int dst = vec.first, cost = vec.second;
                // prune for only the costs that are cheaper than the result
                if (popVals[1] + cost >= res) continue; 
                stk.push({dst, popVals[1] + cost, popVals[2] - 1});
            }
        }
        return res == INT_MAX ? -1 : res; 
    }
};


/*
        // tracks the price of the explored. now if the price is smaller at this explored, than go on and use it
        // vector<int> explored(n, INT_MAX); 
        // {lowest cost, k}
        // vector<pair<int,int>> lowestCostAtLoc(n, {INT_MAX, 0}); 

            // checks if the current price is less than the price at the last exploration at this point for pruning.
            // only valid if the k is the same. otherwise, this might prune out possibilities with stops for others more cheap. 
            // if (popVals[1] >= explored[popVals[0]]) continue;
            // explored[popVals[0]] = popVals[1];
            if (popVals[1] >= lowestCostAtLoc[popVals[0]].first && popVals[2] >= lowestCostAtLoc[popVals[0]].second) continue;
            lowestCostAtLoc[popVals[0]] = make_pair(popVals[1], popVals[2]);

            Does not work with these
*/