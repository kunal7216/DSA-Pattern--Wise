// word replace in a Trie structure
// leetcode 648
// link: https://leetcode.com/problems/replace-words/

// Trie structure for lowercase English alphabets
const int N = 26;

struct Trie
{
    // Array of pointers to child nodes (a–z)
    Trie *next[N];

    // Flag to mark the end of a root word
    bool isEnd = 0;

    // Constructor: initialize all child pointers to NULL
    Trie()
    {
        fill(next, next + N, (Trie *)NULL);
    }

    // Destructor: recursively delete all allocated Trie nodes
    ~Trie()
    {
        for (int i = 0; i < N; ++i)
        {
            if (next[i] != NULL)
            {
                delete next[i]; // free child nodes
            }
        }
    }

    // Insert a word (root word) into the Trie
    void insert(string &word)
    {
        Trie *Node = this;

        // Traverse each character
        for (char c : word)
        {
            int i = c - 'a';

            // Create node if path does not exist
            if (Node->next[i] == NULL)
                Node->next[i] = new Trie();

            Node = Node->next[i];
        }

        // Mark the end of the root word
        Node->isEnd = 1;
    }

    // Find the shortest root prefix of a given word
    string findPrefix(string &word)
    {
        Trie *Node = this;
        string prefix;

        for (char c : word)
        {
            int i = c - 'a';

            // If no matching path exists, return original word
            if (Node->next[i] == NULL)
                return word;

            Node = Node->next[i];
            prefix += c;

            // If a root word ends here, return the prefix
            if (Node->isEnd)
                return prefix;
        }

        // If no root matched fully, return original word
        return word;
    }
};

class Solution
{
public:
    static string replaceWords(vector<string> &dictionary, string &sentence)
    {
        Trie trie;

        // Insert all dictionary root words into the Trie
        for (string &word : dictionary)
            trie.insert(word);

        // Result string and temporary word buffer
        string ans, word;

        // Split sentence by spaces manually
        for (char c : sentence)
        {
            if (c != ' ')
                word += c;
            else
            {
                // Replace current word using Trie
                ans += trie.findPrefix(word);
                ans += ' ';
                word = "";
            }
        }

        // Process the last word
        ans += trie.findPrefix(word);

        return ans;
    }
};
