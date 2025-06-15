#include<bits/stdc++.h>
using namespace std; 

 int solve(int i, int j, int m, int n, vector<vector<int>>& dp) {
        if (i == m - 1 && j == n - 1) return 1; // reached destination
        if (i >= m || j >= n) return 0; // out of bounds

        if (dp[i][j] != -1) return dp[i][j];

        int down = solve(i + 1, j, m, n, dp);
        int right = solve(i, j + 1, m, n, dp);

        dp[i][j] = down + right;
        return dp[i][j];
    }

    int uniquePaths(int m, int n) {
        vector<vector<int>> dp(m, vector<int>(n, -1));
        return solve(0, 0, m, n, dp);
    }

int main() {
    int m, n;
    cin >> m >> n;
    cout << "Unique paths from top-left to bottom-right: " << uniquePaths(m, n) << endl;
    return 0;
}