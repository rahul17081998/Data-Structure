/*
Write a program to solve a Sudoku puzzle by filling the empty cells.

A sudoku solution must satisfy all of the following rules:

Each of the digits 1-9 must occur exactly once in each row.
Each of the digits 1-9 must occur exactly once in each column.
Each of the digits 1-9 must occur exactly once in each of the 9 3x3 sub-boxes of the grid.
The '.' character indicates empty cells.


*/

class Solution {
public:
    /*Complexity

Time: O(9^m), where m is number of empty cells. In the worst case, with each empty cell, 
we have maximum 9 options. But since the board only have 1 valid solution, so this 
time complexity is reduced a lot.
Space: O(1)*/

    vector<pair<int,int>> emptyCells; // vector to store coordinates of empty cells
    int rows[9]={}, cols[9]={}, boxes[9]={}; // arrays to keep track of filled numbers in rows, columns and boxes
    // main fun
    void solveSudoku(vector<vector<char>>& board) {
        // iterate through the board and fill the emptyCells vector and update the rows, cols, and boxes arrays accordingly
        for(int r=0; r<9; r++){
            for(int c=0; c<9; c++){
                if(board[r][c]=='.')
                    emptyCells.push_back({r,c});
                else{
                    int val = board[r][c]-'0';
                    int boxPos = (r/3)*3 + c/3;
                    rows[r] |= 1<<val;
                    cols[c] |= 1<<val;
                    boxes[boxPos] |= 1<<val;
                }
            }
        }
        backTracking(board, 0); // start backtracking to solve the puzzle
    }

    bool backTracking(vector<vector<char>>& board, int i){
        if(i==emptyCells.size()) return true; // if all empty cells are filled, the puzzle is solved
        int r = emptyCells[i].first;
        int c = emptyCells[i].second;
        int boxPos = (r/3)*3 + c/3;

        // try to fill the cell with values 1-9
        for(int val=1; val<=9; val++){
            if(getBit(cols[c], val) || getBit(rows[r], val) || getBit(boxes[boxPos], val))
                continue; // if the value is already filled in the row, column or box, skip to next value
            int oldRow = rows[r], oldCol = cols[c], oldBox = boxes[boxPos];
            board[r][c] = ('0'+val); // fill the empty cell with the current value
            rows[r] |= (1<<val); // mark the current value as filled in the row
            cols[c] |= (1<<val); // mark the current value as filled in the column
            boxes[boxPos] |= (1<<val); // mark the current value as filled in the box

            if(backTracking(board, i+1)) return true; // if the puzzle is solved, return true
            
            // undo the changes and try the next value
            board[r][c] = '.';
            rows[r] =oldRow;
            cols[c] =oldCol;
            boxes[boxPos] =oldBox;
        }
        return false; // if none of the values worked, backtrack
    }

    bool getBit(int x, int val){
        if((x & (1<<val)) >0) return true;
        return false; 
    }
};
