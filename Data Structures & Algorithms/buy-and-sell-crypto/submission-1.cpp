class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int l=0;
        int max=0;
        int n=prices.size();
        for(int r=1;r<n;r++){
            int diff=prices[r]-prices[l];
            if(prices[r]<prices[l]){
                l=r;
            }
            if(diff>max){
                max=diff;
            }
        }
        return max;
    }
};
