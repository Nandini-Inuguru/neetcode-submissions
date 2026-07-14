class Solution {
public:
    int findTargetSumWays(vector<int>& nums, int target) {
        int total = 0;
        for (int x : nums)
            total += x;
        if (abs(target) > total)
            return 0;
        int offset = total;
        int n = nums.size();
        vector<vector<int>> dp(n + 1,vector<int>(2 * total + 1, 0));
        // Sum 0 before processing any number
        dp[0][offset] = 1;
        for (int i = 0; i < n; i++) {
            for (int s = -total; s <= total; s++) {
                if (dp[i][s + offset] == 0)
                    continue;
                dp[i + 1][s + nums[i] + offset] += dp[i][s + offset];
                dp[i + 1][s - nums[i] + offset] += dp[i][s + offset];
            }
        }

        return dp[n][target + offset];
    }
};