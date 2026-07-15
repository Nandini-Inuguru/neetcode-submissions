class Solution {
public:
    int m, n;
    vector<vector<int>> dp;
    vector<pair<int,int>> dir = {
        {1,0},
        {-1,0},
        {0,1},
        {0,-1}
    };

    int dfs(int i, int j, vector<vector<int>>& matrix) {

        if (dp[i][j] != 0)
            return dp[i][j];

        int ans = 1;

        for (auto &d : dir) {

            int ni = i + d.first;
            int nj = j + d.second;

            if (ni >= 0 && ni < m &&
                nj >= 0 && nj < n &&
                matrix[ni][nj] > matrix[i][j]) {

                ans = max(ans, 1 + dfs(ni, nj, matrix));
            }
        }

        dp[i][j] = ans;
        return ans;
    }

    int longestIncreasingPath(vector<vector<int>>& matrix) {

        m = matrix.size();
        n = matrix[0].size();

        dp.assign(m, vector<int>(n, 0));

        int ans = 0;

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                ans = max(ans, dfs(i, j, matrix));
            }
        }

        return ans;
    }
};