class Solution {
public:
    unordered_map<int, vector<int>> graph;
    unordered_set<int> path;
    bool dfs(int course){
        if(path.count(course))
            return false;
        if(graph[course].empty())
            return true;
        path.insert(course);
        for(int pre : graph[course]){
            if(!dfs(pre))
                return false;
        }
        path.erase(course);
        graph[course].clear();
        return true;
    }

    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        for(auto &p : prerequisites){
            graph[p[0]].push_back(p[1]);
        }
        for(int i=0;i<numCourses;i++){
            if(!dfs(i))
                return false;
        }
        return true;
    }
};