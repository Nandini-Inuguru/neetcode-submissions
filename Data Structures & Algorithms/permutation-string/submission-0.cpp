class Solution {
public:
    bool checkInclusion(string s1, string s2) {

        int n1 = s1.length();
        int n2 = s2.length();

        if(n1 > n2){
            return false;
        }

        vector<int> freq1(26,0);
        vector<int> freq2(26,0);

        // frequency of s1
        for(char ch : s1){
            freq1[ch - 'a']++;
        }

        // first window in s2
        for(int i=0;i<n1;i++){
            freq2[s2[i]-'a']++;
        }

        // check first window
        if(freq1 == freq2){
            return true;
        }

        // sliding window
        for(int r=n1;r<n2;r++){

            // add new character
            freq2[s2[r]-'a']++;

            // remove left character
            freq2[s2[r-n1]-'a']--;

            // compare frequencies
            if(freq1 == freq2){
                return true;
            }
        }

        return false;
    }
};