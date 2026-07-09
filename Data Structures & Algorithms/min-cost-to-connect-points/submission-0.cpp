class Solution {
public:
    vector<int> parent;
    vector<int> size;
    int find(int x){
        if(parent[x]==x){
            return x;
        }
        return parent[x]=find(parent[x]);
    }
    bool unite(int a,int b){
        int pa=find(a);
        int pb=find(b);
        if(pa==pb){
            return false;
        }
        if(size[pa]<size[pb]){
            parent[pa]=pb;
            size[pb]+=size[pa];
        }
        else{
            parent[pb]=pa;
            size[pa]+=size[pb];
        }
        return true;
    }
    int minCostConnectPoints(vector<vector<int>>& points) {
        int n=points.size();
        parent.resize(n);
        size.assign(n,1);
        for(int i=0;i<n;i++){
            parent[i]=i;
        }
        vector<vector<int>> edges;
        for(int i=0;i<n;i++){
            for(int j=i+1;j<n;j++){
                int weight= abs(points[i][0]-points[j][0])+abs(points[i][1]-points[j][1]);
                edges.push_back({weight,i,j});
            }
        }
        sort(edges.begin(),edges.end());
        int cost=0;
        int edgesUsed=0;
        for(auto &edge:edges){
            int u=edge[1];
            int v=edge[2];
            if(unite(u,v)){
                cost+=edge[0];
                edgesUsed++;
                if(edgesUsed==n-1){
                    break;
                }
            }
        }
        return cost;
    }
};
