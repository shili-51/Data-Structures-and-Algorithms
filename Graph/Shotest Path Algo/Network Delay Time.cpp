
   int networkDelayTime(vector<vector<int>>& times, int n, int k) {

        vector<pair<int,int>>adj[n+1];

        for(int i = 0; i < times.size(); i++){
            int u = times[i][0];
            int v = times[i][1];
            int time = times[i][2];
            adj[u].push_back({v, time});
        }

        vector<int>timeTaken(n+1, INT_MAX);
        // {time , {node}}
        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>>pq;
        timeTaken[k] = 0;
        pq.push({0,k});

        while(!pq.empty()){
            int time = pq.top().first;
            int node = pq.top().second;
            pq.pop();

            for(auto it: adj[node]){
                int adjNode = it.first;
                int adjNodeTime = it.second;

                if(timeTaken[adjNode] > time + adjNodeTime){
                    timeTaken[adjNode] = time + adjNodeTime;
                    pq.push({timeTaken[adjNode], adjNode});
                }
            }
        }
        
        int minTime = 0;
        for(int i = 1; i <= n; i++){
            if(timeTaken[i] == INT_MAX) return -1;
            minTime = max(minTime, timeTaken[i]);
        }
        return minTime;

    }
