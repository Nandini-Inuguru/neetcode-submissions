class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int l=0;
        int r;
        int sum=0;
        int minLen=nums.size()+1;
        for(int r=0;r<nums.size();r++){
            sum+=nums[r];
            while(sum>=target){
                minLen=min(minLen,r-l+1);
                sum=sum-nums[l];
                l++;
            }
            
        }
        return minLen==nums.size()+1?0:minLen;
    }
};