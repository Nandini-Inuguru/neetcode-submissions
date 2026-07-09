class Solution {
public:
    vector<int> parent;
    vector<int> size;
    int find(int x)
    {
        if (parent[x]==x)
            return x;
        return parent[x] = find(parent[x]);   // Path Compression
    }
    bool unite(int a, int b)
    {
        int pa = find(a);
        int pb = find(b);

        if (pa == pb)
            return false;   // Already in the same component
        // Union by Size
        if (size[pa]<size[pb])
        {
            parent[pa] = pb;
            size[pb] += size[pa];
        }
        else
        {
            parent[pb] = pa;
            size[pa] += size[pb];
        }

        return true;
    }

    int countComponents(int n,vector<vector<int>>& edges)
    {
        parent.resize(n);
        size.assign(n, 1);
        for (int i=0;i<n;i++)
            parent[i]= i;
        int components=n;
        for(auto &e:edges)
        {
            if(unite(e[0],e[1]))
                components--;
        }
        return components;
    }
};