#include<bits/stdc++.h>
using namespace std; 

 int memoization(int i,int j,string& text1,string& text2,vector<vector<int>>& dp){
        if(i<0 || j<0) return 0;
        if(dp[i][j]!=-1) return dp[i][j];
        if(text1[i]==text2[j]) return dp[i][j]=1+memoization(i-1,j-1,text1,text2,dp);
        else return dp[i][j]=max(memoization(i-1,j,text1,text2,dp),memoization(i,j-1,text1,text2,dp));
    }

    int longestCommonSubsequence(string text1, string text2) {
        int m=text1.size(),n=text2.size();
        vector<vector<int>>dp(m,vector<int>(n,-1));
        return memoization(m-1,n-1,text1,text2,dp);
    }

int main() {
    string s1, s2;
    cin >> s1 >> s2;
  
    cout << "Length of LCS: " << longestCommonSubsequence(s1, s2) << endl;
    return 0;
}