// word replace in a Trie structure
// leetcode 648
// link: https://leetcode.com/problems/replace-words/


/*
    Approach 1: Brute Force

    Intuition:
    - For every word in the sentence,
      check every root in the dictionary.
    - If a root is a prefix of the word,
      keep the shortest matching root.
    - If no root matches, keep the original word.

    Time Complexity:
    O(N × D × L)

    N = Number of words in sentence
    D = Number of roots in dictionary
    L = Average root length

    Space Complexity:
    O(1)
*/

class Solution {
public:
    string replaceWords(vector<string>& dictionary, string sentence) {

        stringstream ss(sentence);   // Split sentence into words
        string word;
        string answer;

        // Process every word in the sentence
        while (ss >> word) {

            // Assume no replacement initially
            string shortestRoot = word;

            // Check every root in dictionary
            for (string root : dictionary) {

                // Ignore roots longer than current best answer
                if (root.size() >= shortestRoot.size())
                    continue;

                // Check whether root is a prefix of word
                if (word.substr(0, root.size()) == root) {

                    // Update shortest matching root
                    shortestRoot = root;
                }
            }

            // Add space before every word except first
            if (!answer.empty())
                answer += " ";

            answer += shortestRoot;
        }

        return answer;
    }
};

/*
    Approach 2: Sort Dictionary

    Improvement:
    - Sort roots according to their length.
    - Shortest roots come first.
    - As soon as first prefix matches,
      stop searching.

    Time Complexity:
    Sorting : O(D log D)

    Searching:
    O(N × D × L)

    Space Complexity:
    O(1)
*/

class Solution {
public:
    string replaceWords(vector<string>& dictionary, string sentence) {

        // Sort roots by increasing length
        sort(dictionary.begin(), dictionary.end(),
             [](string &a, string &b) {
                 return a.size() < b.size();
             });

        stringstream ss(sentence);

        string word;
        string answer;

        while (ss >> word) {

            // Default answer is original word
            string replacement = word;

            // Since dictionary is sorted,
            // first matching root is automatically shortest
            for (string root : dictionary) {

                // Ignore impossible roots
                if (root.size() > word.size())
                    break;

                // Prefix found
                if (word.substr(0, root.size()) == root) {

                    replacement = root;

                    // Stop immediately
                    break;
                }
            }

            if (!answer.empty())
                answer += " ";

            answer += replacement;
        }

        return answer;
    }
};

/*
    Approach 3: Trie

    Idea:
    - Store every root inside a Trie.
    - For every word,
      walk through Trie character by character.
    - As soon as we reach an end-of-word node,
      return that prefix.
    - If traversal breaks,
      return original word.

    Time Complexity:
    Building Trie:
    O(Total characters in dictionary)

    Searching:
    O(Total characters in sentence)

    Overall:
    O(D + S)

    D = Total dictionary characters
    S = Total sentence characters

    Space Complexity:
    O(D)
*/

class TrieNode {
public:

    // Pointers for all lowercase letters
    TrieNode* child[26];

    // Marks end of root word
    bool isEnd;

    TrieNode() {

        isEnd = false;

        for (int i = 0; i < 26; i++)
            child[i] = nullptr;
    }
};

class Solution {

    TrieNode* root = new TrieNode();

    // Insert one root into Trie
    void insert(string word) {

        TrieNode* node = root;

        for (char ch : word) {

            int index = ch - 'a';

            // Create node if not present
            if (node->child[index] == nullptr)
                node->child[index] = new TrieNode();

            // Move to next node
            node = node->child[index];
        }

        // Mark end of root
        node->isEnd = true;
    }

    // Find shortest matching root
    string search(string word) {

        TrieNode* node = root;

        string prefix = "";

        for (char ch : word) {

            int index = ch - 'a';

            // No path exists
            // Root not found
            if (node->child[index] == nullptr)
                return word;

            // Move to next character
            node = node->child[index];

            // Build current prefix
            prefix += ch;

            // First completed root found
            // Return immediately because it is shortest
            if (node->isEnd)
                return prefix;
        }

        // Entire word traversed
        // No shorter root exists
        return word;
    }

public:

    string replaceWords(vector<string>& dictionary, string sentence) {

        // Build Trie using all roots
        for (string rootWord : dictionary)
            insert(rootWord);

        stringstream ss(sentence);

        string word;
        string answer;

        // Replace every word
        while (ss >> word) {

            if (!answer.empty())
                answer += " ";

            answer += search(word);
        }

        return answer;
    }
};
