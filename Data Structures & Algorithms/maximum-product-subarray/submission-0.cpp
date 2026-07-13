class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int maxProd=nums[0];
        int minProd=nums[0];
        int ans=nums[0];
        for(int i=1;i<nums.size();i++){
            int tempMax=max({nums[i],maxProd*nums[i],minProd*nums[i]});
            int tempMin=min({nums[i],maxProd*nums[i],minProd*nums[i]});
            maxProd=tempMax;
            minProd=tempMin;
            ans=max(ans,maxProd);
        }
        return ans;
    }
};
