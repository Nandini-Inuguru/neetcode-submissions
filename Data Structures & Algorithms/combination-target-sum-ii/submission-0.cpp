class Solution {
public:

    vector<vector<int>> ans;

    void backtrack(int start,
                   vector<int>& candidates,
                   int target,
                   vector<int>& curr) {

        if(target == 0) {
            ans.push_back(curr);
            return;
        }

        if(target < 0) {
            return;
        }

        for(int i = start; i < candidates.size(); i++) {

            // Skip duplicates
            if(i > start &&
               candidates[i] == candidates[i - 1]) {
                continue;
            }

            curr.push_back(candidates[i]);

            backtrack(i + 1,
                      candidates,
                      target - candidates[i],
                      curr);

            curr.pop_back();
        }
    }

    vector<vector<int>> combinationSum2(vector<int>& candidates,
                                        int target) {

        sort(candidates.begin(),
             candidates.end());

        vector<int> curr;

        backtrack(0,
                  candidates,
                  target,
                  curr);

        return ans;
    }
};