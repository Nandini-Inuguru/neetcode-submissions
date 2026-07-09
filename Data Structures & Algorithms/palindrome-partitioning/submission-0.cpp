class Solution {
public:
    vector<vector<string>> ans;
    bool isPalindrome(string& s,int l,int r){
        while(l<r){
            if(s[l]!=s[r]){
                return false;
            }
            l++;
            r--;
        }
        return true;
    }
    void backtrack(int start,string& s,vector<string>& partition){
        if(start==s.size()){
            ans.push_back(partition);
            return;
        }
        for(int end=start;end<s.size();end++){
            if(!isPalindrome(s,start,end)){
                continue;
            }
            partition.push_back(s.substr(start,end-start+1));
            backtrack(end+1,s,partition);
            partition.pop_back();
        }
    }
    vector<vector<string>> partition(string s) {
        vector<string> partition;
        backtrack(0,s,partition);
        return ans;
    }
};
