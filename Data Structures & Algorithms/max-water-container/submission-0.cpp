class Solution {
public:
    int maxArea(vector<int>& heights) {

        int max = 0;
        int left = 0;
        int right = heights.size() - 1;

        while (left < right) {

            int area =
                (right - left) *
                min(heights[right], heights[left]);

            if (area > max) {
                max = area;
            }

            // move pointer every time
            if (heights[left] < heights[right]) {
                left++;
            }
            else {
                right--;
            }
        }

        return max;
    }
};