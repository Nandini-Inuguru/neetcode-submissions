class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int m=obstacleGrid.size();
        int n=obstacleGrid[0].size();
        vector<vector<int>> dp(m,vector<int>(n,0));
        if(obstacleGrid[m-1][n-1]==1){
            return 0;
        }
        dp[m-1][n-1]=1;
        for(int i=m-1;i>=0;i--){
            for(int j=n-1;j>=0;j--){
                if(i==m-1 && j==n-1){
                    continue;
                }
                if(obstacleGrid[i][j]==1){
                    dp[i][j]=0;
                }
                else{
                    int down=0;
                    int right=0;
                    if(i+1<m){
                        down=dp[i+1][j];
                    }
                    if(j+1<n){
                        right=dp[i][j+1];
                    }
                    dp[i][j]=down+right;
                }
            }
        }
        return dp[0][0];
    }
};