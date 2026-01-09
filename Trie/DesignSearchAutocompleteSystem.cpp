/*    PREMIUM CODE TEMPLATE    
LeetCode 642 – Autocomplete System: Question Summary (Key Points)

Design an autocomplete system that suggests sentences as the user types characters.
The system is initialized with:

    A list of sentences
    Their corresponding usage frequencies.

User inputs characters one at a time.
For each character input (except #), return up to 3 suggestions.
Suggestions are selected based on:

    Highest frequency first
    Lexicographically smallest sentence if frequencies tie.

Input character '#' indicates:

    End of the current sentence
    The sentence should be stored/updated in the system with frequency +1.

After '#', the system resets and waits for a new input.
The system must efficiently handle:

    Prefix matching
    Dynamic updates
    Real-time suggestions

Typical data structure used:

    Trie + sorting / priority logic



*/

// Trie node definition
class TrieNode
{
public:
    // Stores child nodes for each character
    unordered_map<char, TrieNode *> child;

    // Stores sentence → frequency mapping for this prefix
    unordered_map<string, int> count;
};

class AutocompleteSystem
{
private:
    TrieNode *root; // Root of the Trie
    TrieNode *curr; // Pointer to current Trie node while typing
    string prefix;  // Current input prefix

public:
    // Constructor: initializes the system with given sentences and frequencies
    AutocompleteSystem(vector<string> &sentences, vector<int> &times)
    {
        root = new TrieNode();
        curr = root;
        prefix = "";

        // Insert each sentence into the Trie with its frequency
        for (int i = 0; i < sentences.size(); i++)
        {
            insert(sentences[i], times[i]);
        }
    }

    // Inserts a sentence into the Trie with given frequency
    void insert(string s, int time)
    {
        TrieNode *node = root;

        // Traverse each character of the sentence
        for (char c : s)
        {
            // Create child node if it does not exist
            if (!node->child[c])
                node->child[c] = new TrieNode();

            // Move to next node
            node = node->child[c];

            // Update frequency of this sentence for the current prefix
            node->count[s] += time;
        }
    }

    // Processes each input character
    vector<string> input(char c)
    {

        // Case 1: End of sentence input
        if (c == '#')
        {
            // Insert the completed sentence into Trie
            insert(prefix, 1);

            // Reset prefix and current node
            prefix = "";
            curr = root;

            // No suggestions after '#'
            return {};
        }

        // Add current character to prefix
        prefix += c;

        // If no matching prefix exists, create empty path
        if (!curr->child[c])
        {
            curr->child[c] = new TrieNode();
            curr = curr->child[c];
            return {};
        }

        // Move to the next Trie node
        curr = curr->child[c];

        // Collect all sentences matching the current prefix
        vector<pair<string, int>> candidates;
        for (auto &p : curr->count)
        {
            candidates.push_back(p);
        }

        // Sort candidates:
        // 1) Higher frequency first
        // 2) Lexicographically smaller if frequency is same
        sort(candidates.begin(), candidates.end(),
             [](auto &a, auto &b)
             {
                 if (a.second == b.second)
                     return a.first < b.first;
                 return a.second > b.second;
             });

        // Return top 3 results
        vector<string> result;
        for (int i = 0; i < min(3, (int)candidates.size()); i++)
        {
            result.push_back(candidates[i].first);
        }

        return result;
    }
};
