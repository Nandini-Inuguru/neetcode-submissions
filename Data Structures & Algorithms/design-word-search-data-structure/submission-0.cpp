class TrieNode {
public:
    TrieNode* children[26];
    bool endOfWord;

    TrieNode() {
        endOfWord = false;

        for (int i = 0; i < 26; i++) {
            children[i] = nullptr;
        }
    }
};

class WordDictionary {
private:
    TrieNode* root;

    bool dfs(string& word, int index, TrieNode* node) {

        if (node == nullptr)
            return false;

        if (index == word.length())
            return node->endOfWord;

        char ch = word[index];

        if (ch == '.') {

            for (int i = 0; i < 26; i++) {

                if (node->children[i] &&
                    dfs(word, index + 1, node->children[i])) {

                    return true;
                }
            }

            return false;
        }

        int childIndex = ch - 'a';

        return dfs(word,
                   index + 1,
                   node->children[childIndex]);
    }

public:
    WordDictionary() {
        root = new TrieNode();
    }

    void addWord(string word) {

        TrieNode* node = root;

        for (char ch : word) {

            int index = ch - 'a';

            if (node->children[index] == nullptr) {
                node->children[index] = new TrieNode();
            }

            node = node->children[index];
        }

        node->endOfWord = true;
    }

    bool search(string word) {

        return dfs(word, 0, root);
    }
};