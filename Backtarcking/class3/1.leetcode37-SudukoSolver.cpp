/*
37. Sudoku Solver
Hard
Topics
premium lock icon
Companies
Hint
Write a program to solve a Sudoku puzzle by filling the empty cells.

A sudoku solution must satisfy all of the following rules:

Each of the digits 1-9 must occur exactly once in each row.
Each of the digits 1-9 must occur exactly once in each column.
Each of the digits 1-9 must occur exactly once in each of the 9 3x3 sub-boxes of the grid.
The '.' character indicates empty cells.

 

Example 1:


Input: board = [["5","3",".",".","7",".",".",".","."],["6",".",".","1","9","5",".",".","."],[".","9","8",".",".",".",".","6","."],["8",".",".",".","6",".",".",".","3"],["4",".",".","8",".","3",".",".","1"],["7",".",".",".","2",".",".",".","6"],[".","6",".",".",".",".","2","8","."],[".",".",".","4","1","9",".",".","5"],[".",".",".",".","8",".",".","7","9"]]
Output: [["5","3","4","6","7","8","9","1","2"],["6","7","2","1","9","5","3","4","8"],["1","9","8","3","4","2","5","6","7"],["8","5","9","7","6","1","4","2","3"],["4","2","6","8","5","3","7","9","1"],["7","1","3","9","2","4","8","5","6"],["9","6","1","5","3","7","2","8","4"],["2","8","7","4","1","9","6","3","5"],["3","4","5","2","8","6","1","7","9"]]
Explanation: The input board is shown above and the only valid solution is shown below:


 

Constraints:

board.length == 9
board[i].length == 9
board[i][j] is a digit or '.'.
It is guaranteed that the input board has only one solution.
*/
#include<iostream>
using namespace std;
bool isSafe(char digit, int row, int col,vector<vector<char>>& board){
    // 3 rule check krna hai
    // row cheak 
    int n = board.size();
    for(int k = 0; k < n; k++){
        if(board[row][k]== digit){
            // same row me digit pehle se exist krta hai 
            return false;
        }
    }
    // col cheak
    for(int k = 0; k < n; k++){
        if(board[k][col]== digit){
            // same col me digit pehle se exist krta hai 
            return false;
        }
    }
    // 3*3 sub-box cheak
    for(int k = 0; k < n; k++){
        if(board [3*(row/3)+k/3] [3*(col/3)+k/3] == digit){
            // same 3*3 k box me same digit exist krta hai
            return false;
        }
    }
    // agar teeno rules badia follow ho rhi hai to kya krna hai 
    return true;
}
bool solve(vector<vector<char>>& board){
    // entire logic
    // base case?

    // 1 case hum solve krenge, baki recursion sambhal lega
    // sabse pehle find the empty cell
    // empty -> ','
    // we use two for loop
    for(int i = 0; i < board.size(); i++){
        for(int j = 0; j < board[0].size(); j++){
            // main i, j wala cell par aa gaya
            // par pata kese chalega ki data fill kru ki nahi
            // sirf empty cell par fill krenge
            if(board[i][j] == '.'){
                // fill this cell,coz it is empty
                // empty cell pr mujhe 1-> 9 tak digit hit and trial krne hai
                for(int digit = 1; digit<= 9; i++){
                    //  kon sa digit rkhu kese pata chalega
                    // mujhe bas cheak krna hai,k konsa digit rkhna safe hai
                    if(isSafe(digit,i,j,board)== true){
                        // agar safe hai rakhna 
                        board[i][j] = digit;
                        // bakki recursion sambhal lega
                        bool aageSolveHoPaya = solve(board);
                        if(aageSolveHoPaya == false){
                            //  agar solve nhi ho paya to 
                            return true;
                        }
                        else{
                            // agar solve ho gaya
                            // backtrack -> sayad maine galat digit rkh diya hai.
                            board[i][j] = '.';
                        }
                    }
                }
                // agar aap yaha tak pahuch gaye
                // iska matlb ye hai -> ki 1-> 9 tak koi bhi digit yaha par fit nhi ho pa rha hai
                // piche kahin par galti kari hai
                return false;
            }
        }
    }
    // yaha tak aa gaye -> iska matlb 
    // board -> completely fill hogya hai
    // ans aa chuka hai
    return true;
}
void solveSudoku(vector<vector<char>>& board) {
    solve(board);
}
int main(){
    // vector<vector<char>>board = {
    //     {"5","3",".",".","7",".",".",".","."},
    //     {"6",".",".","1","9","5",".",".","."},
    //     {".","9","8",".",".",".",".","6","."},
    //     {"8",".",".",".","6",".",".",".","3"},
    //     {"4",".",".","8",".","3",".",".","1"},
    //     {"7",".",".",".","2",".",".",".","6"},
    //     {".","6",".",".",".",".","2","8","."},
    //     {".",".",".","4","1","9",".",".","5"},
    //     {".",".",".",".","8",".",".","7","9"},
    // };
    return 0;
}