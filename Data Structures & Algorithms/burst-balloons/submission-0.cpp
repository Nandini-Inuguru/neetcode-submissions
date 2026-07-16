class Solution {
public:
    vector<vector<int>> dp;
    int solve(int l, int r, vector<int>& nums) {
        // No balloons left
        if (l > r)
            return 0;
        // Already computed
        if (dp[l][r] != -1)
            return dp[l][r];
        int ans = 0;
        // Try every balloon as the LAST balloon
        for (int i = l; i <= r; i++) {
            // Coins obtained by bursting i LAST
            int coins = nums[l - 1] * nums[i] * nums[r + 1];
            // Solve left interval
            coins += solve(l, i - 1, nums);
            // Solve right interval
            coins += solve(i + 1, r, nums);
            ans = max(ans, coins);
        }
        return dp[l][r] = ans;
    }
    int maxCoins(vector<int>& nums) {
        // Add virtual balloons
        nums.insert(nums.begin(), 1);
        nums.push_back(1);
        int n = nums.size();
        dp.assign(n, vector<int>(n, -1));
        // Solve for original balloons
        return solve(1, n - 2, nums);
    }
};