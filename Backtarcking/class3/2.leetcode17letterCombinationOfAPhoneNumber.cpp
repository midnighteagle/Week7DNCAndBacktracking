
/*
MOST IMPORTANT.
17. Letter Combinations of a Phone Number
Medium
Topics
premium lock icon
Companies
Given a string containing digits from 2-9 inclusive, return all possible letter combinations that the number could represent. Return the answer in any order.

A mapping of digits to letters (just like on the telephone buttons) is given below. Note that 1 does not map to any letters.


 

Example 1:

Input: digits = "23"
Output: ["ad","ae","af","bd","be","bf","cd","ce","cf"]
Example 2:

Input: digits = "2"
Output: ["a","b","c"]
 

Constraints:

1 <= digits.length <= 4
digits[i] is a digit in the range ['2', '9'].
*/
#include<iostream>
#include<vector>
using namespace std;
void solve(unordered_map<char, string> &mapping,vector<string>ans,string &digits, int i, string &output){
    // base case
    if(i >= digits.length()){
        if(output.length()>0){
            ans.push_back(output);
        }
        return;
    }
    // 1 case hum solve krenge, bakki recursion sambhal lega
    char digit = digits[i];
    string mappedString = mapping[digit];

    for(char ch : mappedString){
        // har character ke liye recursive call marni hai
        output.push_back(ch);
        // baki recursion dekhlega
        solve(mapping, ans, digits,i + 1,output);
        // backtracking
        output.pop_back();
    }

}
vector<string> letterCombinations(string digits) {
    vector<string>ans;
    unordered_map<char, string> mapping;
    mapping['2'] = "abc";
    mapping['3'] = "def";
    mapping['4'] = "ghi";
    mapping['5'] = "jkl";
    mapping['6'] = "mno";
    mapping['7'] = "pqrs";
    mapping['8'] = "tuv";
    mapping['9'] = "wxyz";

    int i = 0;
    string output ="";
    solve(mapping,ans,digits,i,output);
    return ans;

}
int main(){
    string digits = "23";
    vector<string> ans = letterCombinations(digits);
    

    return 0;
}