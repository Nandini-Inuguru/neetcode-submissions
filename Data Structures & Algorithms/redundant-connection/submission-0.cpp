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
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        int n=edges.size();
        parent.resize(n+1);
        size.assign(n+1,1);
        for(int i=0;i<=n;i++){
            parent[i]=i;
        }
        for(auto &e: edges){
            if(!unite(e[0],e[1])){
                return e;
            }
        }
        return {};
    }
};
