class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        sort(intervals.begin(),intervals.end());
        int i=1;
        int n=intervals.size();
        int count=0;
        vector<int> curr=intervals[0];
        while(i<n){
            if(intervals[i][0]<curr[1]){
                count++;
                curr[1] = min(curr[1], intervals[i][1]);
            }
            else{
                
                curr=intervals[i];
            }
            i++;
        }
        return count;
    }
};
