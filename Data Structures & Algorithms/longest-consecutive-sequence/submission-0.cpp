class Solution {
public:
    int longestConsecutive(vector<int>& nums) {

        unordered_set<int> numSet(nums.begin(), nums.end());

        int longest = 0;

        for (int num : numSet) {

            // Check if this is start of sequence
            if (numSet.find(num - 1) == numSet.end()) {

                int current = num;
                int streak = 1;

                // Build sequence
                while (numSet.find(current + 1) != numSet.end()) {
                    current++;
                    streak++;
                }

                longest = max(longest, streak);
            }
        }

        return longest;
    }
};