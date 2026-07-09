class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        vector<int> freq(26,0);
        for(char task:tasks){
            freq[task-'A']++;
        }
        priority_queue<int> heap;
        for(int count:freq){
            if(count>0){
                heap.push(count);
            }
        }
        queue<pair<int,int>> q;
        int time=0;
        while(!heap.empty() ||!q.empty()){
            time++;
            if(!heap.empty()){
                int count=heap.top();
                heap.pop();
                count--;
                if(count>0){
                   q.push({count,time+n});
                }
            }
            if(!q.empty() && q.front().second==time){
                heap.push(q.front().first);
                q.pop();
            }
        }
        return time;
    }
};
