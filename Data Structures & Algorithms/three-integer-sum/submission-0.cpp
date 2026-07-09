class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {

        int n = nums.size();

        vector<int> res;
        vector<vector<int>> result;

        sort(nums.begin(), nums.end());

        for (int i = 0; i < n; i++) {

            // skip duplicate i
            if (i > 0 && nums[i] == nums[i - 1]) {
                continue;
            }

            int j = i + 1;
            int k = nums.size() - 1;

            int target = -nums[i];

            while (j < k) {

                if (nums[j] + nums[k] < target) {
                    j++;
                }

                else if (nums[j] + nums[k] > target) {
                    k--;   
                }

                else {

                    res = {nums[i], nums[j], nums[k]};
                    result.push_back(res);

                    j++;
                    k--;

                    // skip duplicates
                    while (j < k && nums[j] == nums[j - 1]) {
                        j++;
                    }

                    while (j < k && nums[k] == nums[k + 1]) {
                        k--;
                    }
                }
            }
        }

        return result;
    }
};