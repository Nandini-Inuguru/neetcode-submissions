class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {

        sort(intervals.begin(), intervals.end());

        vector<vector<int>> ans;

        int i = 1;
        int n = intervals.size();

        vector<int> curr = intervals[0];

        while (i < n) {

            // Overlapping case
            if (intervals[i][0] <= curr[1]) {

                curr[0] = min(curr[0], intervals[i][0]);
                curr[1] = max(curr[1], intervals[i][1]);
            }

            // Non-overlapping case
            else {

                ans.push_back(curr);

                curr = intervals[i];
            }

            i++;
        }

        ans.push_back(curr);

        return ans;
    }
};