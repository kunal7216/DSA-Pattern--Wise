// implementation of Trie (Prefix Tree)
// leetcode 208
// link: https://leetcode.com/problems/implement-trie-prefix-tree/

// ==========================================
// Approach 1 : Brute Force (Vector)
// Time Complexity:
// Insert     : O(1)
// Search     : O(N * L)
// StartsWith : O(N * P)
//
// N = number of words
// L = word length
// P = prefix length
//
// Space Complexity : O(total characters)
// ==========================================

class Trie {
private:
    vector<string> words;

public:
    Trie() {}

    // Insert word into vector
    void insert(string word) {
        words.push_back(word);
    }

    // Search complete word
    bool search(string word) {

        for (string &w : words) {

            if (w == word)
                return true;
        }

        return false;
    }

    // Check prefix
    bool startsWith(string prefix) {

        for (string &w : words) {

            if (w.substr(0, prefix.size()) == prefix)
                return true;
        }

        return false;
    }
};

// ==========================================
// Approach 2 : Hash Set
//
// Insert     : O(L)
// Search     : O(L)
// StartsWith : O(N * P)
//
// Space : O(total characters)
// ==========================================

class Trie {
private:
    unordered_set<string> st;

public:

    Trie() {}

    // Insert word
    void insert(string word) {
        st.insert(word);
    }

    // Search exact word
    bool search(string word) {
        return st.count(word);
    }

    // Prefix search
    bool startsWith(string prefix) {

        for (auto &word : st) {

            if (word.substr(0, prefix.size()) == prefix)
                return true;
        }

        return false;
    }
};

// ========================================================
// Approach 3 : Trie (Optimal)
//
// Time Complexity
// Insert      : O(L)
// Search      : O(L)
// StartsWith  : O(P)
//
// Space : O(total characters)
//
// L = word length
// P = prefix length
// ========================================================

class Trie {

    // Trie Node
    struct TrieNode {

        // Stores pointers for 26 lowercase letters
        TrieNode* children[26];

        // Marks end of a complete word
        bool isEnd;

        TrieNode() {

            // Initially all children are NULL
            for (int i = 0; i < 26; i++)
                children[i] = nullptr;

            isEnd = false;
        }
    };

    // Root node
    TrieNode* root;

public:

    Trie() {
        root = new TrieNode();
    }

    // Insert a word into Trie
    void insert(string word) {

        TrieNode* node = root;

        // Traverse every character
        for (char ch : word) {

            int index = ch - 'a';

            // Create node if it doesn't exist
            if (node->children[index] == nullptr)
                node->children[index] = new TrieNode();

            // Move to next node
            node = node->children[index];
        }

        // Mark end of complete word
        node->isEnd = true;
    }

    // Search complete word
    bool search(string word) {

        TrieNode* node = root;

        for (char ch : word) {

            int index = ch - 'a';

            // Character missing
            if (node->children[index] == nullptr)
                return false;

            node = node->children[index];
        }

        // Word exists only if end is marked
        return node->isEnd;
    }

    // Check whether prefix exists
    bool startsWith(string prefix) {

        TrieNode* node = root;

        for (char ch : prefix) {

            int index = ch - 'a';

            if (node->children[index] == nullptr)
                return false;

            node = node->children[index];
        }

        return true;
    }
};
