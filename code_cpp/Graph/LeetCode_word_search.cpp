/*
Link:https://leetcode.com/problems/word-search/
Given an m x n grid of characters board 
and a string word, return true if word exists in the grid.

The word can be constructed from letters of sequentially adjacent cells, where adjacent 
cells are horizontally or vertically neighboring. The same letter cell may not be used more than once.

*/

class Solution {
public:
    bool dfs(vector<vector<char>> &board, int i, int j, int count, string &word)
    {
        if(word.length() == count)
            return true;
        if(i<0 || i>=board.size() || j<0 || j>=board[i].size() || board[i][j]!=word[count])
            return false;
        // char temp = board[i][j];
        board[i][j] = '0';
        
        bool ans = dfs(board, i+1, j, count+1, word)
            || dfs(board, i-1, j, count+1, word)
            || dfs(board, i, j+1, count+1, word)
            || dfs(board, i, j-1, count+1, word);
            
        board[i][j] = word[count];
        return ans;
    }
    
    bool exist(vector<vector<char>>& board, string word) {
        
        for(int i=0; i<board.size(); i++){
            for(int j=0; j<board[i].size(); j++){
                if(board[i][j] == word[0]){
                    if(dfs(board, i, j, 0, word)){
                        return true;
                    }
                }
            }
        }
        return false;
    }
};
