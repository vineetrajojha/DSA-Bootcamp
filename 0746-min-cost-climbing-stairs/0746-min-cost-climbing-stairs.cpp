class Solution {
public:
    int solve(vector<int>&arr,int i,int n,vector<int>& dp)
    {
        if(i>=n)
            return 0;
        if(dp[i]!=-1)
            return dp[i];
        return dp[i]=arr[i]+min(solve(arr,i+1,n,dp),solve(arr,i+2,n,dp));
    }
    int minCostClimbingStairs(vector<int>& cost) {
        vector<int>dp(cost.size(),-1);
        int ans=min(solve(cost,0,cost.size(),dp),solve(cost,1,cost.size(),dp));
        return ans;
    }
};