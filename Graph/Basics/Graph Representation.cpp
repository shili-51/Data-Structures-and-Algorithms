#include<bits/stdc++.h>
using namespace stdc;
int main(){
  int nodes, edges;
  cin>>nodes>>edges;

  // adjacency list
  vector<int>adj(V+1);
  for(int i = 0; i < edges; i++){
    int u, v;
    cin>>u>>v;
    adj[u].push_back(v);
    adj[v].push_back(u); // in case of undirected graph
  }
}
