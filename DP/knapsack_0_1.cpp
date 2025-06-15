#include<bits/stdc++.h>
using namespace std;    
 int knapsackRec(int W, vector<int> &val, vector<int> &wt, int n, 
                                        vector<vector<int>> &memo) {

    // Base Case
    if (n == 0 || W == 0)
        return 0;

    // Check if we have previously calculated the same subproblem
    if(memo[n][W] != -1)
        return memo[n][W];

    int pick = 0;

    // Pick nth item if it does not exceed the capacity of knapsack
    if (wt[n - 1] <= W)
        pick = val[n - 1] + knapsackRec(W - wt[n - 1], val, wt, n - 1, memo);
    
    // Don't pick the nth item
    int notPick = knapsackRec(W, val, wt, n - 1, memo);
    
    // Store the result in memo[n][W] and return it
    return memo[n][W] = max(pick, notPick);
}

int knapsack(int W, vector<int> &val, vector<int> &wt) {
    int n = val.size();
    
    // Memoization table to store the results
    vector<vector<int>> memo(n + 1, vector<int>(W + 1, -1));
    
    return knapsackRec(W, val, wt, n, memo);
}int main(){
    int n, W;
    cin >> n >> W;
    vector<int> wt(n), val(n);
    for(int i = 0; i < n; i++) {
        cin >> wt[i] >> val[i];
    }
    int ans = knapsack(W, val, wt);
    // Output the maximum value that can be obtained
    cout << "Maximum value in Knapsack: " << ans << endl;
    return 0;
}