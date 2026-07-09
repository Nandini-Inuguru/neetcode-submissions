class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        vector<vector<pair<int,int>>> adj(n+1);
        for(auto &edge:times){
            int u=edge[0];
            int v=edge[1];
            int t=edge[2];
            adj[u].push_back({v,t});
        }
        vector<int> dist(n+1,INT_MAX);
        dist[k]=0;
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;
        pq.push({0,k});
        while(!pq.empty()){
            auto [currDist,node]=pq.top();
            pq.pop();
            if(currDist>dist[node]){
                continue;
            }
            for(auto &[neighbour,weight]:adj[node]){
                if(currDist+weight<dist[neighbour]){
                    dist[neighbour]=currDist+weight;
                    pq.push({dist[neighbour],neighbour});
                }
            }
        }
        int ans=0;
        for(int i=1;i<n+1;i++){
            if(dist[i]==INT_MAX){
                return -1;
            }
            ans=max(ans,dist[i]);
        }
        return ans;
    }
};
