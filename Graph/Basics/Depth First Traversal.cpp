#include <bits/stdc++.h>
using namespace std;

void dfsTraversal(vector<int> adj[], vector<bool>& vis, int src, vector<int>&dfs){

  //mark source node as visited
  vis[src] = true;
  dfs.push_back(src);

  // traverse its neighbourers
  for(auto it: adj[src]){
    if(visited[it] == false){
      dfsTraversal(adj, vis, it, dfs);
    }
  }
}

int main(){
  int nodes, edges;
  cin>>nodes>>edges;
  vector<int>adj(nodes);

  for(int i = 0; i < edges; i++){
    int u, v;
    cin>>u>>v;
    adj[u].push_back(v);
    adj[v].push_back(u);
  }

  vector<bool>vis(nodes, false);
  vector<int>dfs;
  for(int i = 0; i < nodes; i++){
    if(vis[i] == false){
      dfsTraversal(adj, vis, i, dfs);
  }
 }

  for(int i = 0; i < dfs.size(); i++){
     cout<<dfs[i]<<" "; 
  }

}
