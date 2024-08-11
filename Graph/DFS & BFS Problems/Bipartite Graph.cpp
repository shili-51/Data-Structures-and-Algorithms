// https://www.geeksforgeeks.org/problems/bipartite-graph/1

// Bipartite is used in recommedation systems - An edge between a user and a movie indicates that the user has watched or rated the movie. The system can use this bipartite graph to recommend new movies to users by analyzing similar users’ watch history

// One set of nodes represents job seekers, and the other set represents job openings. Edges between them indicate that a candidate is qualified or has applied for a specific job. Algorithms can be used on this bipartite graph to match candidates with suitable jobs.

  bool check(int src, vector<int>& color, vector<int>adj[]){
        
        queue<int>q;
        q.push(src);
        color[src] = 0;
        
        while(q.empty() == false){
            int parentNode = q.front();
            q.pop();
            
            // check whether adjacent nodes are coloured or node
            for(auto it: adj[parentNode]){
                
                // node has not been coloured yet, color it opposite to parent
                if(color[it] == -1){
                    color[it] = !color[parentNode];
                    q.push(it);
                }
                
                // if node is already coloured and with same color as parent - not a bipartite
                else if(color[it] == color[parentNode]){
                    return false;
                }
            }
        }
        return true;
    }
    
	bool isBipartite(int V, vector<int>adj[]){
	    vector<int>color(V,-1);
	    for(int i = 0; i < V; i++){
	        if(color[i] == -1){
	            if(check(i, color, adj) == false) return false;
	        }
	    }
	    return true;
	}
