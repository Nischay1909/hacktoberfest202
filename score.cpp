class Solution {
public:
    int solve(vector<int>& values,int i,int j,vector<vector<int>>&dp){
        if(j-i<2)return 0;
        if(dp[i][j]!=-1)return dp[i][j];
        int mini=INT_MAX;
        for(int k=i+1;k<j;k++){
            int ans=values[i]*values[k]*values[j]+solve(values,i,k,dp)+solve(values,k,j,dp);
            mini=min(mini,ans);
        }
        dp[i][j]=mini;
        return dp[i][j];
    }
    int minScoreTriangulation(vector<int>& values) {
        int n=values.size();
        vector<vector<int>>dp(n,vector<int>(n,-1));
        int result=solve(values,0,n-1,dp);
        return result;
    }
};
