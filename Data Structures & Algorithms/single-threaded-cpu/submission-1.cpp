class Solution {
public:
    vector<int> getOrder(vector<vector<int>>& tasks) {
        vector<vector<int>> v;
        int n=tasks.size();
        for(int i=0;i<tasks.size();i++){
            v.push_back({tasks[i][0],tasks[i][1],i});
        }
        sort(v.begin(),v.end());
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;
        long long cpu=0;
        int i=0;
        vector<int> ans;
        while(!pq.empty()||i<n){
            if(pq.empty()){
                cpu=max(cpu,(long long)v[i][0]);
            }
            while(i<n&&v[i][0]<=cpu){
                pq.push({v[i][1],v[i][2]});
                i++;
            }
            auto[processingTime,index]=pq.top();
            pq.pop();
            ans.push_back(index);
            cpu+=processingTime;
        }
        return ans;
    }
};