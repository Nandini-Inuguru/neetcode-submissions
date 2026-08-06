class Solution {
public:
    int subarraysDivByK(vector<int>& nums, int k) {

        unordered_map<int, int> freq;

        // Prefix sum remainder 0 has appeared once
        freq[0] = 1;

        int prefixSum = 0;
        int ans = 0;

        for (int num : nums) {

            prefixSum += num;

            // Make remainder positive
            int rem = (prefixSum % k + k) % k;

            // If this remainder was seen before,
            // every previous occurrence forms a valid subarray.
            ans += freq[rem];

            // Store this remainder
            freq[rem]++;
        }

        return ans;
    }
};