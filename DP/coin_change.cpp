#include<bits/stdc++.h>
using namespace std;    

int f(int ind, int W, vector<int> &coins, vector<vector<int>> &dp) {
    // Base Case: If no coins are left or weight is zero
    if (ind == 0) {
        return (W % coins[0] == 0);
    }
    
    // Check if the result is already computed
    if (dp[ind][W] != -1) {
        return dp[ind][W];
    }
    
    // Option 1: Do not take the current coin
    int notTake = f(ind - 1, W, coins, dp);
    
    // Option 2: Take the current coin if it does not exceed the weight
    int take = 0;
    if (coins[ind] <= W) {
        take = f(ind, W - coins[ind], coins, dp);
    }
    
    // Store the result in the DP table and return the sum of both options
    return dp[ind][W] = take + notTake;
}
int main(){

    int n, W;
    cin >> n >> W;
    vector<int> coins(n);
    for(int i = 0; i < n; i++) {
        cin >> coins[i];
    }

    // Initialize a DP array to store the number of ways to make change
    vector<vector<int>> dp(n + 1, vector<int>(W + 1, 0));
    int ans=f(n,W,coins,dp);

    return 0;

}