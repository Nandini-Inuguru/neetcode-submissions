class Solution {
public:
    vector<int> minInterval(vector<vector<int>>& intervals, vector<int>& queries) {
        sort(intervals.begin(),intervals.end());
        vector<pair<int,int>> q;
        for(int i=0;i<queries.size();i++){
            q.push_back({queries[i],i});
        }
        sort(q.begin(),q.end());
        int i=0;
        vector<int> ans(queries.size());
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> heap;
        for(auto& query:q){
            int val=query.first;
            int idx=query.second;
            while(i<intervals.size()&&intervals[i][0]<=val){
                int start=intervals[i][0];
                int end=intervals[i][1];
                int length=end-start+1;
                heap.push({length,end});
                i++;
            }
            while(!heap.empty()&&heap.top().second<val){
                heap.pop();
            }
            if(heap.empty()){
                ans[idx]=-1;
            }
            else{
                ans[idx]=heap.top().first;
            }
        }
        return ans;
    }
};
