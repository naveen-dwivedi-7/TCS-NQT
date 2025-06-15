#include<bits/stdc++.h>
using namespace std;    

int f(int ind, int n, vector<int> &price, vector<int> &length, vector<vector<int>> &dp) {
    // Base Case: If no length is left or no rod pieces are available
    if (ind == 0) {
        return (n / length[0]) * price[0];
    }
    
    // Check if the result is already computed
    if (dp[ind][n] != -1) {
        return dp[ind][n];
    }
    
    // Option 1: Do not take the current piece
    int notTake = f(ind - 1, n, price, length, dp);
    int take=INT_MIN;
    if(length[ind] <= n) {
        take = price[ind] + f(ind, n - length[ind], price, length, dp);
    }
    // Store the result in the DP table and return the maximum of both options
    return dp[ind][n] = max(take, notTake);
}
int rodCutting(int n, vector<int> &price, vector<int> &length) {
    // Create a DP array to store the maximum price for each length
    vector<vector<int>> dp(n + 1, vector<int>(n + 1, -1));

    // Return the maximum price that can be obtained for length n
    return f(n-1, n, price, length, dp);
}

int main() {
    int n, W;
    cin >> n >> W;
    vector<int> price(n), length(n);
    for(int i = 0; i < n; i++) {
        cin >> length[i] >> price[i];
    }
    int ans = rodCutting(W, price, length);

    // Output the maximum price that can be obtained
    cout << "Maximum price obtainable: " << ans << endl;

    return 0;
}