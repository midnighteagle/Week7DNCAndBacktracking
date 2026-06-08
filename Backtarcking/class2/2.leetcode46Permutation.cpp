/*
46. Permutations
Medium
Topics
premium lock icon
Companies
Given an array nums of distinct integers, return all the possible permutations. You can return the answer in any order.

 

Example 1:

Input: nums = [1,2,3]
Output: [[1,2,3],[1,3,2],[2,1,3],[2,3,1],[3,1,2],[3,2,1]]
Example 2:

Input: nums = [0,1]
Output: [[0,1],[1,0]]
Example 3:

Input: nums = [1]
Output: [[1]]
 

Constraints:

1 <= nums.length <= 6
-10 <= nums[i] <= 10
*/

#include<iostream>
using namespace std;
void solve(vector<int>&nums, int i, vector<vector<int>> &ans){
    // base case
    if(i >= nums.size()){
        ans.push_back(nums);
        return;
    }
    // 1 case main solve krunga , baki recursion solve kr dega 
    // permutation :- ith place par sab ko chance dena hai 
    for(int j = i ; j < nums.size(); j++){
        // swap kro pehle
        swap(nums[i], nums[j]);
        solve(nums, i+1, ans);
        // backTrack
        swap(nums[i], nums[j]);
    }
}
vector<vector<int>> permute(vector<int>&nums){
    vector<vector<int>> ans;
    int i = 0;
    solve(nums,i,ans);
    return ans;
}
int main(){
    vector<int>nums = {1,2,3};
    vector<vector<int>> ans = permute(nums);
    for(auto row : ans) {
        for(auto element : row) {
            cout << element << " ";
        }
        cout << endl;
    }
    

    return 0;
}