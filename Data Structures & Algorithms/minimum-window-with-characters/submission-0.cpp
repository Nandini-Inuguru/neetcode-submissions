class Solution {
public:
    string minWindow(string s, string t) {

        unordered_map<char, int> countT;
        unordered_map<char, int> window;

        // frequency of t
        for(char ch : t){
            countT[ch]++;
        }

        int have = 0;
        int need = countT.size();

        int l = 0;

        int minLen = INT_MAX;
        int start = 0;

        for(int r = 0; r < s.length(); r++){

            char ch = s[r];

            // add char to window
            window[ch]++;

            // valid frequency achieved
            if(countT.find(ch) != countT.end() &&
               window[ch] == countT[ch]){

                have++;
            }

            // shrink window if valid
            while(have == need){

                // update smallest answer
                if((r - l + 1) < minLen){

                    minLen = r - l + 1;
                    start = l;
                }

                // remove left char
                window[s[l]]--;

                // window became invalid
                if(countT.find(s[l]) != countT.end() &&
                   window[s[l]] < countT[s[l]]){

                    have--;
                }

                l++;
            }
        }

        if(minLen == INT_MAX){
            return "";
        }

        return s.substr(start, minLen);
    }
};