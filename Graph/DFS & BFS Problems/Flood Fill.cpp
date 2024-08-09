// https://leetcode.com/problems/flood-fill/

class Solution {
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        
        if (image[sr][sc] == color) return image;
        int row = image.size();
        int col = image[0].size();

        queue<pair<int,int>>q;
        q.push({sr, sc});

        int old = image[sr][sc];
        image[sr][sc] = color;

        int dx[4] = {-1,1,0,0};
        int dy[4] = {0,0,-1,1};

        while(q.empty() == false) {
            int x = q.front().first;
            int y = q.front().second;
            q.pop();

            for(int i = 0; i < 4; i++){
                int currx = x + dx[i];
                int curry = y + dy[i];
                if(currx >= 0 && currx < row && curry >= 0 && curry < col && image[currx][curry] == old && image[currx][curry] != color){
                    image[currx][curry] = color;
                    q.push({currx, curry});
                }
            }
        }
        return image;  
    }
};
