// https://leetcode.com/problems/surrounded-regions/

// Apply dfs on edges cells and mark them *, then convert all Os to X, then replace all * to Os

class Solution {
public:
    void change(int x,int y,vector<vector<char>>& board)
    {
        board[x][y]='*';
        int dx[4] = {-1,1,0,0};
        int dy[4] = {0,0,-1,1};
        for(int i=0;i<4;i++)
        {
            int currx = x + dx[i];
            int curry = y + dy[i];
            if(currx>=0 && currx<board.size() && curry>=0 && curry<board[0].size() && board[currx][curry]=='O')
            {
                change(currx,curry,board);
            }
        }
        return;
    }
    void solve(vector<vector<char>>& board) {
        int n = board.size();
        int m = board[0].size();
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(i==0 || i==n-1 || j==0 || j==m-1)
                {
                    if(board[i][j]=='O'){
                        change(i,j,board);
                    }
                }
            }
        }
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(board[i][j]=='O')
                    board[i][j] = 'X';
            }
        }
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(board[i][j]=='*')
                    board[i][j] = 'O';
            }          
        }
    }
};
