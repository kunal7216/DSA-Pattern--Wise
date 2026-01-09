// Design Add and Search Words Data Structure
// LeetCode Problem 211
// https://leetcode.com/problems/design-add-and-search-words-data-structure/

// Trie node definition
class TrieNode
{
public:
    // Array of pointers for 26 lowercase English letters
    TrieNode *child[26];

    // Marks the end of a valid word
    bool end = false;

    // Constructor: initialize all child pointers as NULL
    TrieNode()
    {
        for (int i = 0; i < 26; i++)
            child[i] = NULL;
    }
};

class WordDictionary
{
    TrieNode *root; // Root of the Trie

public:
    // Constructor: create an empty root node
    WordDictionary()
    {
        root = new TrieNode();
    }

    // Adds a word into the Trie
    void addWord(string word)
    {
        TrieNode *node = root;

        // Traverse each character of the word
        for (char c : word)
        {
            int idx = c - 'a'; // Convert character to index (0–25)

            // If the path does not exist, create a new Trie node
            if (!node->child[idx])
                node->child[idx] = new TrieNode();

            // Move to the next node
            node = node->child[idx];
        }

        // Mark the end of the word
        node->end = true;
    }

    // Public search function (starts recursion)
    bool search(string word)
    {
        return search(word, 0, root);
    }

    // Recursive search helper function
    bool search(string &word, int idx, TrieNode *node)
    {

        // If node becomes NULL, path is invalid
        if (!node)
            return false;

        // If all characters are processed,
        // check if this node marks the end of a word
        if (idx == word.size())
            return node->end;

        // If current character is NOT a wildcard
        if (word[idx] != '.')
        {
            // Move to the corresponding child node
            return search(word, idx + 1, node->child[word[idx] - 'a']);
        }

        // If current character is '.',
        // try all possible 26 children
        for (int key = 0; key < 26; key++)
        {
            if (search(word, idx + 1, node->child[key]))
                return true; // If any path matches, return true
        }

        // No valid path found
        return false;
    }
};
