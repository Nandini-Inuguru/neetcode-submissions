class Solution {
public:
    string mergeAlternately(string word1, string word2) {
        string result;
        int top=0;
        int bot=0;
        while(top!=word1.size()&&bot!=word2.size()){
            result.push_back(word1[top]);
            result.push_back(word2[bot]);
            top++;
            bot++;
        }
        if(top<word1.size()){
            result+=word1.substr(top);
        }
        if(bot<word2.size()){
            result+=word2.substr(bot);
        }
        return result;
    }
};