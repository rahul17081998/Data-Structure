/*
We have given Number N we need to consider NxN chessboard and we need to place
N queens on this chess board such that no two queens attacks each other.
*/

#include<iostream>
using namespace std;

#define N 4 
  
int board[N][N];  
// print the solved matrix
void printSolution(int board[N][N])
{
    for(int i=0; i<N; i++){
        for(int j=0; j<N; j++){
            cout<<board[i][j]<<" ";
        }
        cout<<"\n";
    }
}
// mainly check thet placing the queen at row,col position is safe or not
bool isSafe(int row, int col)
{
    // it checks with the current row 
    // have we any queen in the current row
    for(int i=0; i<col; i++)
        if(board[row][i])
            return false;

    // check in upper digonal
    for(int i=row, j=col; i>=0 && j>=0; i--,j--)
        if(board[i][j])
            return false;

    // check in lower digonal
    for(int i=row, j=col; j>=0 && i<N; i++,j--)
        if(board[i][j])
            return false;

    return true;
}

// main function
bool solveRec(int col)
{
    // you already placed all the queens
    if(col==N) return true;

    // if column is not N then it try to 
    // placing the queen at different row of current column
    for (int i = 0; i < N; i++)
    {
        if(isSafe(i, col))
        {
            board[i][col] = 1;
            if(solveRec(col+1))
                return true;
            board[i][col] = 0;  // if solver gives false it remove queen from perticular place
        }
    }
    return false;
}


// repper function which call solveRec() function
bool solve()
{
    if(solveRec(0) == false){
        cout<<"solution does not exist.\n";
        return false;
    }

    else{
        cout<<"Solution exist and queens can be placed at these positions\n";
        printSolution(board);
        
        return true;
    } 

}
int main(){
    solve();
    
    return 0;
}