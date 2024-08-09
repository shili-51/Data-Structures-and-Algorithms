#include<bits/stdc++.h>
using namespace std;

void dfs(int src, vector<bool>& visited, vector<int> adj[]){
  visited[src] = true;

  // visiting all neighbourers of src in depth
  for(auto it: adj[src]){
    if(visited[it] == false){
      dfs(it, visited, adj);
    }
  }
}

int main(){
  int nodes, edges;
  cin>>nodes>>edges;
  vector<int>adj[nodes + 1];
  for(int i = 0; i < edges; i++){
    int u, v;
    cin>>u>>v;
    adj[u].push_back(v);
    adj[v].push_back(u);
  }

  vector<bool>visited(nodes + 1, false);
  int ConnectedComponents = 0;

  for(int i = 0; i < nodes; i++){
    ConnectedComponents++;
    dfs(i, visited, adj);
  }

  cout<<ConnectedComponents;

}
