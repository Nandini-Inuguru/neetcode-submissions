class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string,vector<string>> map;
        for(string str:strs){
            vector <int> freq(26,0);
            for(char ch: str){
                freq[ch-'a']++;
            }
            string key="";
            for(int count:freq){
                key+=to_string(count)+"#";
            }
            map[key].push_back(str);
        }
        vector<vector<string>> result;
        for(auto pair:map){
            result.push_back(pair.second);
        }

    return result;    
    }
};
