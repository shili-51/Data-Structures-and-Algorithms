// https://www.geeksforgeeks.org/problems/detect-cycle-in-a-directed-graph/1?itm_source=geeksforgeeks&itm_medium=article&itm_campaign=practice_card

bool help(int V,vector<int>adj[],bool vis[],bool rec[],int s){
  
        vis[s] = true;
        // including node in current recursion stack
        rec[s] = true;
  
        for(auto x:adj[s])
        {
            if(vis[x]==false)
            {
                if(help(V,adj,vis,rec,x)==true) return true;
            }
            else if(rec[x]==true)  // if node is already visited and is part of current recursion stack , there is cycle
            return true;
        }

        // exclude node from current recursion stack
        rec[s]=false;
        return false;
    }
    bool isCyclic(int V, vector<int> adj[]) {
        bool vis[V+1]={false};
        bool rec[V+1]={false};
        for(int i=0;i<V;i++)
        {
            if(vis[i]==false)
            {
                if(help(V,adj,vis,rec,i)==true) return true;
            }
        }
        return false;
    }
