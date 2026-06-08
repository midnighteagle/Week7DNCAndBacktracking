/*
51. N-Queens
Hard
Topics
premium lock icon
Companies
The n-queens puzzle is the problem of placing n queens on an n x n chessboard such that no two queens attack each other.

Given an integer n, return all distinct solutions to the n-queens puzzle. You may return the answer in any order.

Each solution contains a distinct board configuration of the n-queens' placement, where 'Q' and '.' both indicate a queen and an empty space, respectively.

 

Example 1:


Input: n = 4
Output: [[".Q..","...Q","Q...","..Q."],["..Q.","Q...","...Q",".Q.."]]
Explanation: There exist two distinct solutions to the 4-queens puzzle as shown above
Example 2:

Input: n = 1
Output: [["Q"]]
 

Constraints:

1 <= n <= 9
*/
#include<iostream>
using namespace std;
unordered_map<int,bool>rowCheak;
unordered_map<int,bool>lowerDiagonalCheak;
unordered_map<int,bool>upperDiagonalCheak;
void storeSolution(vector<vector<string>> &ans,vector<vector<char>> &board,int n){
    vector<string>tempAns;
    for(int i = 0; i < n; i++){
        string output = "";
        for(int j = 0; j < n; j++){
            output.push_back(board[i][j]);
        }
        // string is ready 
        tempAns.push_back(output);
    }
    // vector of string is ready
    ans.push_back(tempAns);
}
bool isSafe(int row, int col, vector<vector<char>>&board){
    // bruteforce -> traverse board -> t.c -> n^2 -> nhi krenge bcz take more time.
    // linear time complexity
    // cheakk for row
    if(rowCheak[row] ==true){
        // not Safe
        return false;
    }
    // cheak for upper diagonal
    if(upperDiagonalCheak[row-col] == true){
        // not safe
        return false;
    }
    // cheack for lower diagonal
    if(lowerDiagonalCheak[row+col]==true){
        // not safe
        return false;
    }
    // else safe to place 
    return true;
}
void solve(int n,vector<vector<char>>&board,vector<vector<string>> &ans, int col ){
    // base case
    if(col >= n){
        // all Queen are placed
        // store board arrangement in ans
        storeSolution(ans, board, n);
        return;
    }
    // 1 case main solve krunga and baki recursion sambhal lega
    // mere pass col ka index hai, uss column me konsi row me queen ko place karna hai
    // vo yaha decide hoga
    for(int row = 0; row < n; row++){
        // har row par queen ko place kr k dekhunga
        if(isSafe(row,col,board)){
            board [row][col] = 'Q'; // inversted commma bhul jata hu
            rowCheak[row] = true;
            upperDiagonalCheak[row+col] = true;
            lowerDiagonalCheak[row-col] = true;
            // baaki kon sambhalega
            // recursion
            solve(n,board, ans, col+1);
            // backtracking 
            // ye main bhul jata hu
            board[row][col] = '.';
            rowCheak[row] = false;
            upperDiagonalCheak[row+col] = false;
            lowerDiagonalCheak[row-col] = false;

        }
    }

}
vector<vector<string>> solveNQueens(int n){
    vector<vector<string>> ans;
    // board
    vector<vector<char>>board(n,vector<char>(n,'.'));
    // starting the placeing Queens with 0th column
    int col = 0;
    solve (n,board,ans,col);
    return ans;
}
int main(){
    int n = 4;
    vector<vector<string>>ans = solveNQueens(n);
    for(auto row : ans) {
        for(auto element : row) {
            cout << element << ","<<" ";
        }
        cout << endl;
    }
    return 0;
}