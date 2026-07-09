class Solution {
public:
    vector<vector<int>> ans;

    void backtrack(int idx,
                   vector<int>& nums,
                   vector<int>& subset) {

        if(idx == nums.size()) {
            ans.push_back(subset);
            return;
        }

        // Include nums[idx]
        subset.push_back(nums[idx]);
        backtrack(idx + 1, nums, subset);

        // Backtrack
        subset.pop_back();

        // Exclude nums[idx]
        backtrack(idx + 1, nums, subset);
    }

    vector<vector<int>> subsets(vector<int>& nums) {

        vector<int> subset;

        backtrack(0, nums, subset);

        return ans;
    }
};