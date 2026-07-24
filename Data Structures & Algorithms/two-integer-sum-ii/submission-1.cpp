class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        int n=numbers.size();
        if(target<numbers[0]+numbers[1] || target>numbers[n-2]+numbers[n-1]){
            return {};
        }
        int left=0;
        int right=numbers.size()-1;
        while(left<right){
            if(numbers[right]+numbers[left]>target){
                right--;
            }
            else if(numbers[right]+numbers[left]<target){
                left++;
            }
            else{
                return {left+1,right+1};
            }
        }
        return {};
    }
};
