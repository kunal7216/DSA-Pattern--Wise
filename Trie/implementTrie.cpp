// implementation of Trie (Prefix Tree)
// leetcode 208
// link: https://leetcode.com/problems/implement-trie-prefix-tree/

// Trie node structure
class TrieNode
{
public:
    // Array of pointers for 26 lowercase English letters
    TrieNode *child[26];

    // Flag to mark the end of a valid word
    bool isWord;

    // Constructor
    TrieNode()
    {
        isWord = false;

        // Initialize all children as null
        for (auto &a : child)
            a = nullptr;
    }
};

class Trie
{
    TrieNode *root; // Root node of the Trie

public:
    // Constructor: create an empty root node
    Trie()
    {
        root = new TrieNode();
    }

    // Insert a word into the Trie
    void insert(string s)
    {
        TrieNode *p = root;

        // Traverse each character of the word
        for (auto &a : s)
        {
            int i = a - 'a'; // Map character to index (0–25)

            // If the child does not exist, create a new node
            if (!p->child[i])
                p->child[i] = new TrieNode();

            // Move to the next node
            p = p->child[i];
        }

        // Mark the end of the word
        p->isWord = true;
    }

    // Search for a word or prefix
    bool search(string key, bool prefix = false)
    {
        TrieNode *p = root;

        // Traverse through the characters
        for (auto &a : key)
        {
            int i = a - 'a';

            // If path breaks, word/prefix not found
            if (!p->child[i])
                return false;

            p = p->child[i];
        }

        // If searching for a full word, check isWord flag
        if (prefix == false)
            return p->isWord;

        // If searching for prefix only, traversal success is enough
        return true;
    }

    // Check if any word starts with the given prefix
    bool startsWith(string prefix)
    {
        return search(prefix, true);
    }
};
