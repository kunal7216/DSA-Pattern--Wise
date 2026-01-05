// word search II
// leetcode 212
// link: https://leetcode.com/problems/word-search-ii/

class Solution
{
public:
    /* ---------------- TRIE NODE DEFINITION ---------------- */
    struct TrieNode
    {
        TrieNode *child[26]; // Pointers for 26 lowercase letters
        bool flag = false;   // Marks end of a valid word
        string str;          // Stores complete word at end node

        // Constructor: initialize all children to NULL
        TrieNode()
        {
            for (int i = 0; i < 26; i++)
                child[i] = NULL;
        }

        // Check if current node has a child for character ch
        bool containChar(char ch)
        {
            return child[ch - 'a'] != NULL;
        }

        // Create a new child node for character ch
        void putNode(char ch, TrieNode *node)
        {
            child[ch - 'a'] = node;
        }

        // Move to the next Trie node for character ch
        TrieNode *getNode(char ch)
        {
            return child[ch - 'a'];
        }

        // Mark this node as end of a word
        void setEnd()
        {
            flag = true;
        }

        // Check if this node represents end of a word
        bool isEnd()
        {
            return flag;
        }
    };

    // Root of the Trie
    TrieNode *root = new TrieNode();

    /* ---------------- INSERT WORD INTO TRIE ---------------- */
    void insert(string word)
    {
        TrieNode *node = root;

        // Traverse each character of the word
        for (int i = 0; i < word.size(); i++)
        {

            // If character path does not exist, create it
            if (!node->containChar(word[i]))
            {
                node->putNode(word[i], new TrieNode());
            }

            // Move to next node
            node = node->getNode(word[i]);
        }

        // Mark the end of the word
        node->setEnd();

        // Store full word at end node
        node->str = word;
    }

    /* ---------------- DFS SEARCH ON BOARD ---------------- */
    void dfs(vector<vector<char>> &board,
             int i, int j,
             TrieNode *node,
             set<string> &res,
             vector<vector<bool>> &visit)
    {

        // Boundary check
        if (i < 0 || j < 0 ||
            i >= board.size() ||
            j >= board[0].size())
            return;

        char ch = board[i][j];

        // If already visited OR no Trie path exists
        if (visit[i][j] || !node->containChar(ch))
            return;

        // Move Trie pointer
        node = node->getNode(ch);

        // If a word ends here, store it
        if (node->isEnd())
            res.insert(node->str);

        // Mark cell as visited
        visit[i][j] = true;

        // Explore all 4 directions
        dfs(board, i + 1, j, node, res, visit); // Down
        dfs(board, i - 1, j, node, res, visit); // Up
        dfs(board, i, j + 1, node, res, visit); // Right
        dfs(board, i, j - 1, node, res, visit); // Left

        // Backtrack: unmark visited
        visit[i][j] = false;
    }

    /* ---------------- MAIN FUNCTION ---------------- */
    vector<string> findWords(vector<vector<char>> &board,
                             vector<string> &words)
    {

        // Insert all words into Trie
        for (string &s : words)
            insert(s);

        set<string> res; // Avoid duplicates

        // Visited matrix for DFS
        vector<vector<bool>> visit(
            board.size(),
            vector<bool>(board[0].size(), false));

        // Start DFS from every cell
        for (int i = 0; i < board.size(); i++)
        {
            for (int j = 0; j < board[0].size(); j++)
            {
                dfs(board, i, j, root, res, visit);
            }
        }

        // Convert set to vector
        return vector<string>(res.begin(), res.end());
    }
};
