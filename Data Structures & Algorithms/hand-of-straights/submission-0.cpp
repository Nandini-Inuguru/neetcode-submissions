class Solution {
public:
    bool isNStraightHand(vector<int>& hand, int groupSize) {

        if(hand.size() % groupSize != 0)
            return false;

        unordered_map<int,int> freq;

        for(int card : hand) {
            freq[card]++;
        }

        sort(hand.begin(), hand.end());

        for(int card : hand) {

            if(freq[card] == 0)
                continue;

            for(int i = 0; i < groupSize; i++) {

                int curr = card + i;

                if(freq[curr] == 0)
                    return false;

                freq[curr]--;
            }
        }

        return true;
    }
};