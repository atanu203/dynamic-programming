#include<bits/stdc++.h>
using namespace std;

int frogJumpRecursion(int indx, vector<int> heights) {
    if(indx == 0) return 0;
    int left = frogJumpRecursion(indx-1, heights) + abs(heights[indx] - heights[indx-1]);
    int right = INT_MAX;
    if(indx > 1){
        right = frogJumpRecursion(indx-2, heights) + abs(heights[indx] - heights[indx-2]);
    }
    return min(left, right);
}

int frogJump(int indx, vector<int> heights, vector<int>& dp) {
    // Memoization | TC - O(n), SC - O(2n)
    /*
    if(indx == 0) return 0;
    if(dp[indx] != -1) return dp[indx];
    int jump2 = INT_MAX;
    int jump1 = frogJump(indx-1, heights, dp) + abs(heights[indx] - heights[indx-1]);
    if(indx > 1){
        jump2 = frogJump(indx-2, heights, dp) + abs(heights[indx] - heights[indx-2]);
    }
    return dp[indx] = min(jump1, jump2);
    */

    // Tabulation | TC - O(n), SC - O(2n)
    dp[0] = 0;
    int jump1, jump2;
    for(int indx=1; indx<heights.size(); indx++){
        jump1 = dp[indx-1] + abs(heights[indx] - heights[indx-1]);
        jump2 = INT_MAX;
        if(indx > 1){
            jump2 = dp[indx-2] + abs(heights[indx] - heights[indx-2]);
        }
        dp[indx] = min(jump1, jump2);
    }
    return dp[indx];
}

// Space Optimized | TC - O(n), SC - O(1)
int spaceOptimized(int N, vector<int> heights) {
    int prev1 = 0, prev2 = 0;
    for(int i=1; i<N; i++){
        int jump2 = INT_MAX;
        int jump1 = prev1 + abs(heights[i] - heights[i-1]);
        if(i > 1){
            jump2 = prev2 + abs(heights[i] - heights[i-2]);
        }
        int curr = min(jump1, jump2);
        prev2 = prev1;
        prev1 = curr;
    }
    return prev1;
}

int main() {
    vector<int> height = {30, 10, 60, 10, 60, 50};
    int n = height.size();
    vector<int> dp(n, -1);

    cout << spaceOptimized(n, height);

    return 0;
}