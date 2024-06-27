// https://www.geeksforgeeks.org/problems/fruit-into-baskets-1663137462/1

int totalFruits(int N, vector<int> &fruits) {
        unordered_map<int,int>mp;
        int i = 0;
        int j = 0;
        int ans = 0;
        while( j < N){
            mp[fruits[j]]++;
            if(mp.size() > 2){
                mp[fruits[i]]--;
                if(mp[fruits[i]] == 0) mp.erase(fruits[i]);
                i++;
            }
            if(mp.size() <= 2) ans = max(ans, j - i + 1);
            j++;
        }
        return ans;
    }
