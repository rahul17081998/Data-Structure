/*
The n-queens puzzle is the problem of placing n queens on an n x n chessboard such that no two queens attack each other.

Given an integer n, return all distinct solutions to the n-queens puzzle. You may return the answer in any order.

Each solution contains a distinct board configuration of the n-queens' placement, where 'Q' and '.' both indicate a queen and an empty space, respectively.



*/
class Solution {
public:
    vector<vector<string>> res;
    int colarr = 0, nd = 0, rd = 0; // nd -> normal diagonal, rd -> reverse diagonal
    
    bool getBit(int pos, int val){
        // Get the bit at position `pos` in the binary representation of `val`
        if((1 << pos) & val) return true;
        return false;
    }
    
    void dfs(vector<string> &board, int row){
        // If we have placed all `n` queens, add the configuration to the result
        if(row == board.size()){
            res.push_back(board);
            return;
        }
        
        // Try placing a queen in each column of the current row
        for(int col = 0; col < board.size(); col++){
            // Check if the column, normal diagonal, or reverse diagonal is already occupied by a queen
            if(getBit(col, colarr) || getBit(row + col, nd) || getBit(row - col + board.size() - 1, rd)) {
                continue;
            }
            
            // Place the queen in the current cell
            board[row][col] = 'Q';
            
            // Toggle the bits in the bitmask variables to indicate that this cell is occupied
            colarr ^= (1 << col);
            nd ^= (1 << (row + col));
            rd ^= (1 << (row - col + board.size() - 1));
            
            // Recursively place the queens in the remaining rows
            dfs(board, row + 1);
            
            // Backtrack by removing the queen and resetting the bitmask variables
            board[row][col] = '.';
            colarr ^= (1 << col);
            nd ^= (1 << (row + col));
            rd ^= (1 << (row - col + board.size() - 1));
        }
    }

    vector<vector<string>> solveNQueens(int n) {
        vector<string> board(n, string(n, '.')); // Initialize the board with empty cells
        dfs(board, 0); // Start placing queens from the first row
        return res; // Return all valid configurations of the board
    }
};
