class DisjointSet
{
    vector<int>parent,size;
    public:
    DisjointSet(int V){
        parent.resize(V+1);
        size.resize(V+1);
        for(int i = 0; i <= V; i++){
            parent[i] = i;
            size[i] = 1;
        }
    }
    
    int ultimateParent(int node){
        if(parent[node] == node) return node;
        return parent[node] = ultimateParent(parent[node]);
        
    }
    
    void unionSet(int u, int v){
        int parent_u = ultimateParent(u);
        int parent_v = ultimateParent(v);
        
        if(parent_u == parent_v) return;
        
        else if(size[parent_u] < size[parent_v]){
            // u is smaller than v
            // u will get attached to v, 
            // increasing size of v & change of parent of u to v
            parent[parent_u] = parent_v;
            size[parent_v] += size[parent_u];
        } else{
            parent[parent_v] = parent_u;
            size[parent_u] += size[parent_v];
        }
    }
    
};



class Solution
{
	public:
	//Function to find sum of weights of edges of the Minimum Spanning Tree.
    int spanningTree(int V, vector<vector<int>> adj[])
    {
        vector<pair<int,pair<int,int>>>edge;
        for(int i = 0; i < V; i++){
            for(auto it: adj[i]){
                int v = it[0];
                int wt = it[1];
                edge.push_back({wt,{i, v}});
            }
        }
        
        sort(edge.begin(), edge.end());
        DisjointSet dsu(V);
        int mstwt = 0;
        
        for(auto it: edge){
            int wt = it.first;
            int u = it.second.first;
            int v = it.second.second;
            
            if(dsu.ultimateParent(u) != dsu.ultimateParent(v)){
                mstwt += wt;
                dsu.unionSet(u,v);
            }
        }
        return mstwt;
    }
