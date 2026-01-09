// Search suggestions system
// LeetCode Problem 642 
// https://leetcode.com/problems/design-search-autocomplete-system/

// Trie node structure
struct TrieNode
{
    // Each node can have 26 children (a–z)
    TrieNode *children[26] = {NULL};

    // True if a complete word ends at this node
    bool endOfWord = false;
};

class Solution
{
public:
    // Function to insert a word into the Trie
    void insertWord(TrieNode *trie, string &word)
    {
        for (char &c : word)
        {
            // Convert character to index (0–25)
            int index = c - 'a';

            // If child node does not exist, create it
            if (!trie->children[index])
            {
                trie->children[index] = new TrieNode();
            }

            // Move to the next node
            trie = trie->children[index];
        }

        // Mark the end of the word
        trie->endOfWord = true;
    }

    // Function to search words matching a prefix
    vector<string> searchWord(TrieNode *trie, string &prefix)
    {
        vector<string> result;

        // Traverse the Trie using the prefix
        for (char &c : prefix)
        {
            int index = c - 'a';

            // If prefix path does not exist, return empty result
            if (!trie->children[index])
                return {};

            trie = trie->children[index];
        }

        // Perform DFS from the prefix node to find suggestions
        dfs(trie, prefix, result);

        return result;
    }

    // DFS helper to collect up to 3 lexicographically smallest words
    void dfs(TrieNode *trie, string pre, vector<string> &result)
    {
        // Stop once we have 3 suggestions
        if (result.size() == 3)
            return;

        // If current node marks a word, add it
        if (trie->endOfWord)
            result.push_back(pre);

        // Explore all children in alphabetical order
        for (int i = 0; i < 26; i++)
        {
            if (trie->children[i])
            {
                dfs(trie->children[i],
                    pre + char(i + 'a'),
                    result);
            }
        }
    }

    // Main function required by LeetCode
    vector<vector<string>> suggestedProducts(vector<string> &products, string search)
    {
        // Create Trie root
        TrieNode *trie = new TrieNode();

        // Insert all products into the Trie
        for (string &prod : products)
            insertWord(trie, prod);

        vector<vector<string>> result;
        string prefix;

        // Build prefix character by character
        for (char &c : search)
        {
            prefix += c;

            // Get suggestions for current prefix
            result.push_back(searchWord(trie, prefix));
        }

        return result;
    }
};
