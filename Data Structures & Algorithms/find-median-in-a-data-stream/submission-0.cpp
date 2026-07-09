class MedianFinder {
public:
    priority_queue<int> left;
    priority_queue<int,vector<int>,greater<int>> right;
    MedianFinder() {
        
    }
    
    void addNum(int num) {
        if(right.empty()||num>=right.top()){
            right.push(num);
        }
        else{
            left.push(num);
        }
        if(right.size()>left.size()+1){
            left.push(right.top());
            right.pop();
        }
        if(left.size()>right.size()+1){
            right.push(left.top());
            left.pop();
        }
        
    }
    
    double findMedian() {
        if(left.size()>right.size()){
            return left.top();
        }
        else if(right.size()>left.size()){
            return right.top();
        }
        return (double)(left.top()+right.top())/2;
        
    }
};
