class Solution {
public:

    string encode(vector<string>& strs) {
        string result="";
        for(string str:strs){
            result += to_string(str.length()) + "#" + str;

        }
        return result;

    }

    vector<string> decode(string s) {
        vector<string> result;
        int i=0;
        while(i<s.length()){
            int j=i;
            while(s[j]!='#'){
                j++;
            }
            int length=stoi(s.substr(i,j-i));
            string word=s.substr(j+1,length);
            result.push_back(word);
            i=j+1+length;

        }
        return result;

    }
};
