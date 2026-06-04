/*
Rat in a Maze
Difficulty: MediumAccuracy: 35.75%Submissions: 419K+Points: 4Average Time: 25m

Consider a rat placed at position (0, 0) in an n x n square matrix maze[][]. The rat's goal is to reach the destination at position (n-1, n-1). The rat can move in four possible directions: 'U'(up), 'D'(down), 'L' (left), 'R' (right).

The matrix contains only two possible values:

0: A blocked cell through which the rat cannot travel.
1: A free cell that the rat can pass through.
Your task is to find all possible paths the rat can take to reach the destination, starting from (0, 0) and ending at (n-1, n-1), under the condition that the rat cannot revisit any cell along the same path. Furthermore, the rat can only move to adjacent cells that are within the bounds of the matrix and not blocked.
If no path exists, return an empty list.

Note: Return the final result vector in lexicographically smallest order.

Examples:

Input: maze[][] = [[1, 0, 0, 0], [1, 1, 0, 1], [1, 1, 0, 0], [0, 1, 1, 1]]
Output: ["DDRDRR", "DRDDRR"]
Explanation: The rat can reach the destination at (3, 3) from (0, 0) by two paths - DRDDRR and DDRDRR, when printed in sorted order we get DDRDRR DRDDRR.
Input: maze[][] = [[1, 0], [1, 0]]
Output: []
Explanation: No path exists as the destination cell (1, 1) is blocked.
Input: maze[][] = [[1, 1, 1], [1, 0, 1], [1, 1, 1]]
Output: ["DDRR", "RRDD"]
Explanation: The rat has two possible paths to reach the destination: DDRR and RRDD.
Constraints:
2 ≤ n ≤ 5
0 ≤ maze[i][j] ≤ 1
*/
#include<iostream>
#include<vector>
using namespace std;
bool issafe(int new_X,int new_Y,vector<vector<int>> &m,vector<vector<bool>>&visited,int n){
    if(new_X < 0 || new_Y < 0 || new_X >= n || new_Y >= n){
        //out of bound 
        return false;
    }
    if(visited [new_X][new_Y] == true){
        // already visited 
        return false;
    }
    if(m[new_X][new_Y] == 0){
        // blocked space
        return false;
    }
    // valid case 
    return true;
}
void solve(vector<vector<int>> &m,vector<vector<bool>>&visited,int n, vector<string>&ans,int src_X,int src_Y, int des_X, int des_Y, string output){
    // base case
    if(src_X == des_X && src_Y == des_Y){
        // rat reached destination 
        // store output string ko ans me
        ans.push_back(output);
        return;
    }

    // int dx[] = {-1,1,0,0};
    // int dy[] = {0,0,-1,1};
    // char move[] = {'U','D','L','R'};
    // for(int i=0 ; i < 4; i++){
    //     int newX= src_X + dx[i];
    //     int newY= src_Y + dx[i];
    //     char movement = move[i];

    //     visited[newX][newY] = true;
    //     output.push_back(movement);
    //     solve(m,visited,n,ans,newX,newY, des_X,des_Y,output);
    //     // wapas aaunga, toh visited toh revert karna padega
    //     // backtracking
    //     output.pop_back();
    //     visited[newX][newY] = false;
    // }


    // 1 case hum solve krenge baki recursion sambhal lega
    // 1case  -> up, down, left ,right
    
    // up
    // i,j -> i-1,j;

    int new_X = src_X - 1;
    int new_Y = src_Y;
    if(issafe(new_X,new_Y, m, visited, n)){
        visited[new_X][new_Y] = true;
        solve(m,visited,n,ans,new_X,new_Y, des_X,des_Y,output + "U");
        // wapas aaunga, toh visited toh revert karna padega
        // backtracking
        visited[new_X][new_Y] = false;
    }
    // down->  i,j -> i+1,j
    new_X = src_X + 1;
    new_Y = src_Y;
    if(issafe(new_X,new_Y, m, visited, n)){
        visited[new_X][new_Y] = true;
        solve(m,visited,n,ans,new_X,new_Y, des_X,des_Y,output + "D");
        // wapas aaunga, toh visited toh revert karna padega
        // backtracking
        visited[new_X][new_Y] = false;
    }
    // left ->i,j -> i, j-1
    new_X = src_X ;
    new_Y = src_Y - 1;
    if(issafe(new_X,new_Y, m, visited, n)){
        visited[new_X][new_Y] = true;
        solve(m,visited,n,ans,new_X,new_Y, des_X,des_Y,output + "L");
        // wapas aaunga, toh visited toh revert karna padega
        // backtracking
        visited[new_X][new_Y] = false;
    }
    // right -> i,j -> i,j+1;
    new_X = src_X ;
    new_Y = src_Y + 1;
    if(issafe(new_X,new_Y, m, visited, n)){
        visited[new_X][new_Y] = true;
        solve(m,visited,n,ans,new_X,new_Y, des_X,des_Y,output + "R");
        // wapas aaunga, toh visited toh revert karna padega
        // backtracking
        visited[new_X][new_Y] = false;
    }
}
vector<string> findPath(vector<vector<int>> &m, int n){
    //code here!!
    vector<string>ans;
    vector<vector<bool>>visited(n, vector<bool>(n,0));
    // rat ke row and col index k liye niche wale 2 variable le rha hu
    int src_X = 0;
    int src_Y = 0;
    // main yaha par galti krta hu!!
    // start me Rat (0,0) pr hoga, that why visited ko true mark kro
    visited[0][0] = true;
    // Destination k row and col index k liye 2 variable use krra hai
    int des_X = n-1;
    int des_Y = n-1;
    // answer build krne ke liye !!
    string output = " ";

    // important Case
    if(m[0][0] == 0){
        // rat is starting position block hai return empty ans
        return ans;
    }
    // function call
    solve(m,visited,n,ans,src_X,src_Y,des_X,des_Y,output);
    return ans;
}
int main(){
    vector<vector<int>>m={
    {1,0,0,0},
    {1,1,0,1},
    {1,1,0,0},
    {0,1,1,1}
    };
    int n = 4;
    vector<string> ans = findPath(m,n);
    for(string s : ans){
        cout << s << endl;
    }
    return 0;
}