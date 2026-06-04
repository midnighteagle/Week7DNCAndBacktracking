/*
Painting Fence Algorithm
Last Updated : 11 Nov, 2024
Given a fence with n posts and k colors, the task is to find out the number of ways of painting the fence so that not more than two consecutive posts have the same color.

Examples:

Input: n = 2, k = 4
Output: 16
Explanation: We have 4 colors and 2 posts.
Ways when both posts have same color: 4 
Ways when both posts have diff color: 4(choices for 1st post) * 3(choices for 2nd post) = 12

Input: n = 3, k = 2
Output: 6
Explanation: The following image depicts the 6 possible ways of painting 3 posts with 2 colors:
Using Recursion - O(2^n) Time and O(n) Space



The idea is to define our solution in terms of two choices: painting the last post a different color from the previous one or painting the last two posts the same color. This gives us the recurrence relation:

countWays(n) = countWays(n-1)*(k-1) + countWays(n-2)*(k-1)

Case 1: Different Color for the Last Post
If we paint the last post a different color from the one before it, we have k-1 choices (all colors except the previous post’s color). This means the number of ways to paint the first n-1 posts is multiplied by k-1.

Case 2: Same Color for the Last Two Posts
If the last two posts are the same color, they must differ from the post before them (the third-last post). Thus, we have k-1 choices for the last two posts, and the number of ways to paint the first n-2 posts is given by countWays(n-2).
*/
#include<iostream>
#include<vector>
using namespace std;
int getPaintWays(int n, int k){
    // base case 
    if(n == 1){
        return k;
    }
    if(n == 2){
        return k + (k * (k-1));
    }
    int ans = (k-1) * (getPaintWays(n - 1, k) + getPaintWays(n - 2, k));
    return ans;
}
int main()
{
    int n = 3;
    int k = 3;
    int ans = getPaintWays(n,k);
    cout<< "number of color: "<<ans<<endl;
    return 0;
}