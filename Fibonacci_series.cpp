#include<bits/stdc++.h>
using namespace std;

int fiboSeries(int n, vector<int>& dp) {
    // Memoization | TC - O(n), SC - O(2n)
    /*
    if(n <= 1) return n;
    if(dp[n] != -1){
        return dp[n];
    }
    return dp[n] = fiboSeries(n-1, dp) + fiboSeries(n-2, dp);
    */

    // Tabulation | TC - O(n), SC - O(n)
    dp[0] = 0;
    dp[1] = 1;
    for(int i=2; i<=n; i++){
        dp[i] = dp[i-1] + dp[i-2];
    }
    return dp[n];
}

// Space optimised | TC - O(n), SC - O(1)
int optiFibo(int n) {
    int prev2 = 0;
    int prev1 = 1;
    for(int i=2; i<=n; i++){
        int curi = prev1 + prev2;
        prev2 = prev1;
        prev1 = curi;
    }
    return prev1;
}

int main() {
    int N;
    cout << "Enter fibonacci term: ";
    cin >> N;
    vector<int> dp(N+1, -1);

    // Memoization & Tabulation
    // cout << fiboSeries(N, dp);
    // Space Optimized
    cout << optiFibo(N);

    return 0;
}