class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
      vector<int> dp(amount+1,amount+1);
      dp[0]=0;
      for(int a=0;a<=amount;a++){
        for(auto &coin:coins){
            if(coin<=a){
                dp[a]=min(dp[a],1+dp[a-coin]);
            }
        }
      }
      if(dp[amount]==amount+1){
        return -1;
      }
      return dp[amount];
    }
};
