class Solution {
public:
    vector<vector<int>> ans;
    void backtrack(int start,vector<int>& nums,vector<int>& subset){       
        ans.push_back(subset);       
        for(int i=start;i<nums.size();i++){
            if(i>start && nums[i]==nums[i-1])
            continue;
            subset.push_back(nums[i]);
            backtrack(i+1,nums,subset);
            subset.pop_back();
            

        }

    }
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector<int> subset;
        sort(nums.begin(),nums.end());
        backtrack(0,nums,subset);
        return ans;
    }
};
