class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {

        vector<int> result;

        // max heap -> {value, index}
        priority_queue<pair<int,int>> maxHeap;

        for(int i = 0; i < nums.size(); i++) {

            // push current element and index
            maxHeap.push({nums[i], i});

            // remove elements outside window
            while(maxHeap.top().second <= i - k) {
                maxHeap.pop();
            }

            // window formed
            if(i >= k - 1) {
                result.push_back(maxHeap.top().first);
            }
        }

        return result;
    }
};