class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        priority_queue<int> heap;
        for(int num:stones){
            heap.push(num);
        }
        while(heap.size()>1){
            int x=heap.top();
            heap.pop();
            int y=heap.top();
            heap.pop();
            if(x!=y){
                heap.push(x-y);
            }

        }
        if(heap.empty()){
            return 0;
        }
        else{
            return heap.top();
        }
    }
};
