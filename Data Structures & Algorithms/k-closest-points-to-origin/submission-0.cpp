class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        priority_queue<pair<int,vector<int>>> heap;
        for(auto& point:points){
            int x=point[0];
            int y=point[1];
            int dist=x*x+y*y;
            heap.push({dist,point});
            if(heap.size()>k){
                heap.pop();
            }
        }
        vector<vector<int>> ans;
        while(!heap.empty()){
            ans.push_back(heap.top().second);
            heap.pop();
        }

        return ans;
    }
};
