#include<bits/stdc++.h>
using namespace std; 

  int solve(int i, int j, int m, int n, vector<vector<int>>& dp, vector<vector<int>> &obstacleGrid) {
        if (i == m - 1 && j == n - 1) return 1; // reached destination
        if (i >= m || j >= n || obstacleGrid[i][j] == 1) return 0; // Out of bounds or obstacle

        if (dp[i][j] != -1) return dp[i][j];

        int down = solve(i + 1, j, m, n, dp,obstacleGrid);
        int right = solve(i, j + 1, m, n, dp,obstacleGrid);

        dp[i][j] = down + right;
        return dp[i][j];
    }

   
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int m=obstacleGrid.size(),n=obstacleGrid[0].size();
        vector<vector<int>> dp(m, vector<int>(n, -1));
                if (obstacleGrid[0][0] == 1 || obstacleGrid[m - 1][n - 1] == 1) return 0;

        return solve(0, 0, m, n, dp,obstacleGrid);
    }
int main() {
    int m, n;
    cin >> m >> n;
    vector<vector<int>> obstacleGrid(m, vector<int>(n));
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            cin >> obstacleGrid[i][j];
        }
    }
    cout << "Unique paths from top-left to bottom-right: " << uniquePathsWithObstacles(obstacleGrid) << endl;
    return 0;
}