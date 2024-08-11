// https://www.geeksforgeeks.org/problems/eventual-safe-states/0

// reversal of graph (no outward edges which on reverse changes to all outward edges)
// checks for dependency of all the other nodes getting resolved completely after removal of terminal nodes dependency (ensures those nodes can surely reach terminal)
// indegree[adjacent node of terminal] becoming 0 after removal of dependency of terminal node


    vector<int> eventualSafeNodes(int V, vector<int> adj[]) {
        // code here
        
        // after reversing graph
        // original graph outdegree == reversed graph indegree
        vector<int> rev[V];
        
        vector<int>indegree(V, 0);
        
        for(int i = 0; i < V; i++){
            for(auto it: adj[i]){
                rev[it].push_back(i);
                indegree[i]++;
            }
        }
        
        queue<int>q;
        for(int i = 0; i < V; i++){
            if(indegree[i] == 0){
                q.push(i);
            }
        }
        
        vector<int>safeNodes;
        
        while(!q.empty()){
            int curr = q.front();
            q.pop();
            safeNodes.push_back(curr);
            
            for(auto it: rev[curr]){
                indegree[it]--;
                if(indegree[it] == 0){
                    q.push(it);
                }
            }
        }
        
        sort(safeNodes.begin(), safeNodes.end());
        return safeNodes;
    }
