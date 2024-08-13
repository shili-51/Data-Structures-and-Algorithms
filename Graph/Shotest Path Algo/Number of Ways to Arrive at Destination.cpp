G-40
// ways to reach current node = summation of ways to reach all the adjacent nodes of current node

    int countPaths(int n, vector<vector<int>>& roads) {
        vector<pair<long long,long long>>adj[n];
        for(int i = 0; i < roads.size(); i++){
            long long firstCity = roads[i][0];
            long long secondCity = roads[i][1];
            long long time = roads[i][2];
            adj[firstCity].push_back({secondCity,time});
            adj[secondCity].push_back({firstCity, time});
        }
        
        vector<long long>ways(n,0);
        vector<long long>timeTaken(n, LONG_MAX);
        priority_queue<pair<long long,long long>, vector<pair<long long,long long>>, greater<pair<long long,long long>>>pq;
        // {time, node}
        pq.push({0,0});
        ways[0] = 1;
        timeTaken[0] = 0;
        
        while(!pq.empty()){
            long long city = pq.top().second;
            long long time = pq.top().first;
            pq.pop();
            
            // traverse adjacent cities
            for(auto it: adj[city]){
                long long adjCity = it.first;
                long long adjCityTime = it.second;
                
                if(timeTaken[adjCity] > time + adjCityTime){
                    timeTaken[adjCity] = time + adjCityTime;
                    ways[adjCity] = ways[city];
                    pq.push({time + adjCityTime, adjCity});
                }
                else if(timeTaken[adjCity] == time + adjCityTime){
                    ways[adjCity] = (ways[adjCity] + ways[city]) % 1000000007;
                }
                
            }
        }
        return ways[n-1]% 1000000007;
