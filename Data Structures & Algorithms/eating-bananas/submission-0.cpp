class Solution {
public:

    int minEatingSpeed(vector<int>& piles, int h) {

        int left = 1;
        int right = *max_element(piles.begin(), piles.end());

        int ans = right;

        while(left <= right) {

            int k = left + (right - left) / 2;

            long long hours = 0;

            for(int pile : piles) {
                hours += (pile + k - 1) / k;
            }

            if(hours <= h) {
                ans = k;          // valid speed
                right = k - 1;   // try smaller speed
            }
            else {
                left = k + 1;    // too slow
            }
        }

        return ans;
    }
};