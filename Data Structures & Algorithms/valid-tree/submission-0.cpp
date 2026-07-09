class Solution {
public:

    vector<vector<int>> adj;
    vector<bool> visited;
    bool dfs(int node,int parent){
        if(visited[node]){
            return false;
        }
        visited[node]=true;
        for(int next:adj[node]){
            if(next==parent){
                continue;
            }
            if(!dfs(next,node)){
                return false;
            }
        }
        return true;
    }
    bool validTree(int n, vector<vector<int>>& edges) {
        if(edges.size()!=n-1){
            return false;
        }
        adj.resize(n);
        for(auto &e:edges){
            adj[e[0]].push_back(e[1]);
            adj[e[1]].push_back(e[0]);
        }
        visited.assign(n,false);
        if(!dfs(0,-1)){
            return false;
        }
        for(bool v:visited){
            if(!v){
                return false;
            }
        }
        return true;
    }
};
