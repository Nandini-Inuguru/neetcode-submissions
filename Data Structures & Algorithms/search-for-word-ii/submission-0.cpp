class Solution {
public:

    class TrieNode {
    public:
        TrieNode* children[26];
        int wordIndex;

        TrieNode() {
            wordIndex = -1;

            for(int i = 0; i < 26; i++)
                children[i] = nullptr;
        }
    };

    void dfs(vector<vector<char>>& board,
             int r,
             int c,
             TrieNode* node,
             vector<string>& words,
             vector<string>& ans) {

        if(r < 0 || c < 0 ||
           r >= board.size() ||
           c >= board[0].size())
            return;

        char ch = board[r][c];

        if(ch == '#')
            return;

        node = node->children[ch - 'a'];

        if(node == nullptr)
            return;

        if(node->wordIndex != -1) {

            ans.push_back(words[node->wordIndex]);

            node->wordIndex = -1;
        }

        board[r][c] = '#';

        dfs(board, r + 1, c, node, words, ans);
        dfs(board, r - 1, c, node, words, ans);
        dfs(board, r, c + 1, node, words, ans);
        dfs(board, r, c - 1, node, words, ans);

        board[r][c] = ch;
    }

    vector<string> findWords(vector<vector<char>>& board,
                             vector<string>& words) {

        TrieNode* root = new TrieNode();

        for(int i = 0; i < words.size(); i++) {

            TrieNode* node = root;

            for(char ch : words[i]) {

                int idx = ch - 'a';

                if(node->children[idx] == nullptr)
                    node->children[idx] =
                        new TrieNode();

                node = node->children[idx];
            }

            node->wordIndex = i;
        }

        vector<string> ans;

        for(int i = 0; i < board.size(); i++) {

            for(int j = 0; j < board[0].size(); j++) {

                dfs(board,
                    i,
                    j,
                    root,
                    words,
                    ans);
            }
        }

        return ans;
    }
};