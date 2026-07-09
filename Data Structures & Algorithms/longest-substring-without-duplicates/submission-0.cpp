class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int l=0;
        unordered_set<char> seen;
        int n=s.length();
        int maxLength=0;
        for(int r=0;r<n;r++){
           while(seen.find(s[r]) != seen.end()){
            seen.erase(s[l]);
            l++;
           }
           seen.insert(s[r]);
           maxLength=max(maxLength,r-l+1);
        }
        return maxLength;
    }
};
