class Solution {
public:
    int characterReplacement(string s, int k) {
        int l=0;
        int maxLen=0;
        int maxFreq=0;
        unordered_map<char,int> freq;
        for(int r=0;r<s.size();r++){
            freq[s[r]]++;
            maxFreq=max(maxFreq,freq[s[r]]);
            while(((r-l+1)-maxFreq)>k){
                freq[s[l]]--;
                l++;
            
            }
            maxLen=max(maxLen,r-l+1);
        }
        return maxLen;
    }
};
