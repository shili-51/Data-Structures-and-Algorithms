// https://leetcode.com/problems/word-search/

class Solution {

    public boolean findCharInMaze(char[][] matrix, String word, int index, int row, int col, int i, int j){

        if(index == word.length()) return true;

        if(i < 0 || j < 0 || i >= row || j >= col || matrix[i][j] != word.charAt(index)) return false;

        char nextchar = word.charAt(index);
        
        // mark visited for board[i][j]
        char c = matrix[i][j];
        matrix[i][j] = '*';


        // look for word[index] in all directions
        // right - findCharInMaze(matrix, word, index + 1, row, col, i, j + 1)
        // left - findCharInMaze(matrix, word, index + 1, row, col, i, j - 1)
        // top - findCharInMaze(matrix, word, index + 1, row, col, i - 1, j)
        // bottom - findCharInMaze(matrix, word, index + 1, row, col, i + 1, j)

        boolean ans = ((findCharInMaze(matrix, word, index + 1, row, col, i, j + 1)) || (findCharInMaze(matrix, word, index + 1, row, col, i, j - 1)) || (findCharInMaze(matrix, word, index + 1, row, col, i - 1, j)) || (findCharInMaze(matrix, word, index + 1, row, col, i + 1, j))); 

        matrix[i][j] = c;
        return ans;
    }



    public boolean exist(char[][] board, String word) {
        int row = board.length;
        int col = board[0].length;
        for(int i = 0; i < row; i++){
            for(int j = 0; j < col; j++){
                if(board[i][j] == word.charAt(0)){
                    if(findCharInMaze(board, word, 0, row, col, i, j) == true){
                        return true;
                    }
                }
            }
        }
        return false;
    }
}
