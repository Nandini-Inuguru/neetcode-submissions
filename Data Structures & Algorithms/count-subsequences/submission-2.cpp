class Solution {
public:
    vector<vector<long long>> dp;
    long long dfs(int i, int j, string &s, string &t) {
        // Entire target formed
        if (j == t.size())
            return 1;
        // Source finished before target
        if (i == s.size())
            return 0;
        // Already computed
        if (dp[i][j] != -1)
            return dp[i][j];
        // Characters match
        if (s[i] == t[j]) {
            long long take = dfs(i + 1, j + 1, s, t);
            long long skip = dfs(i + 1, j, s, t);
            return dp[i][j] = take + skip;
        }
        // Characters don't match
        return dp[i][j] = dfs(i + 1, j, s, t);
    }
    int numDistinct(string s, string t) {
        int m = s.size();
        int n = t.size();
        dp.assign(m, vector<long long>(n,-1));
        return dfs(0, 0, s, t);
    }
};