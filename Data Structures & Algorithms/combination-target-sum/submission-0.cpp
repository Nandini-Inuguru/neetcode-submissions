class Solution {
public:
    vector<vector<int>> ans;
    void backtrack(int idx,vector<int>& nums,int target,vector<int>& curr){
        if(target==0){
            ans.push_back(curr);
            return;
        }
        if(idx==nums.size()||target<0){
            return;
        }
        curr.push_back(nums[idx]);
        backtrack(idx,nums,target-nums[idx],curr);
        curr.pop_back();
        backtrack(idx+1,nums,target,curr);
    }
    vector<vector<int>> combinationSum(vector<int>& nums, int target) {
        vector<int> curr;
        backtrack(0,nums,target,curr);
        return ans;
    }
};
