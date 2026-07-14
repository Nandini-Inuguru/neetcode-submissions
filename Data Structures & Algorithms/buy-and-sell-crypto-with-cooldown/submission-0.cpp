class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        // dp[i][1] = Maximum profit starting from day i when we CAN BUY
        // dp[i][0] = Maximum profit starting from day i when we ALREADY OWN a stock
        // n+2 because after selling we jump to i+2 (cooldown)
        vector<vector<int>> dp(n + 2, vector<int>(2, 0));

        // Fill the table from the last day to the first day
        for (int i = n - 1; i >= 0; i--) {

            // ---------------- CAN BUY STATE ----------------
            // Option 1: Buy today
            int buy = -prices[i] + dp[i + 1][0];

            // Option 2: Skip today
            int skip = dp[i + 1][1];

            dp[i][1] = max(buy, skip);

            // ---------------- HOLDING STOCK STATE ----------------
            // Option 1: Sell today
            int sell = prices[i] + dp[i + 2][1];

            // Option 2: Keep holding
            int hold = dp[i + 1][0];

            dp[i][0] = max(sell, hold);
        }

        // Start from day 0 with no stock
        return dp[0][1];
    }
};