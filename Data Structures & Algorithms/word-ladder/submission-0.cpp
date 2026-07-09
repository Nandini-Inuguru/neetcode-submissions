class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {

        unordered_map<string, vector<string>> patternMap;

        // Build pattern -> words map
        for (string word : wordList) {
            for (int i = 0; i < word.size(); i++) {
                string pattern = word;
                pattern[i] = '*';
                patternMap[pattern].push_back(word);
            }
        }

        queue<pair<string, int>> q;
        q.push({beginWord, 1});

        unordered_set<string> visited;
        visited.insert(beginWord);

        while (!q.empty()) {

            auto [word, level] = q.front();
            q.pop();

            if (word == endWord)
                return level;

            for (int i = 0; i < word.size(); i++) {

                string pattern = word;
                pattern[i] = '*';

                for (string &nextWord : patternMap[pattern]) {

                    if (!visited.count(nextWord)) {
                        visited.insert(nextWord);
                        q.push({nextWord, level + 1});
                    }
                }

                // Clear the list so we don't process the same pattern again
                patternMap[pattern].clear();
            }
        }

        return 0;
    }
};