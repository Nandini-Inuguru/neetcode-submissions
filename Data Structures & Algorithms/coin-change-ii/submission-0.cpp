class Solution {
public:
    int change(int amount, vector<int>& coins) {

        // dp[j] = Number of ways to make amount j
        vector<int> dp(amount + 1, 0);

        // Base case:
        // There is one way to make amount 0:
        // choose no coins.
        dp[0] = 1;

        // Process each coin one by one
        for (int coin : coins) {

            // Try to make every amount from coin to amount
            for (int j = coin; j <= amount; j++) {

                // Ways without using current coin
                //      +
                // Ways by taking one current coin
                dp[j] += dp[j - coin];
            }
        }

        // Answer: number of ways to make 'amount'
        return dp[amount];
    }
};