// word ladder
// leetcode: https://leetcode.com/problems/word-ladder/

class Solution
{
public:
    int ladderLength(string beginWord, string endWord, vector<string> &wordList)
    {

        // Map to store intermediate patterns and corresponding words
        // Example: "*ot" -> {"hot", "dot", "lot"}
        unordered_map<string, vector<string>> patternMap;

        // Insert beginWord into wordList to include it in pattern generation
        wordList.push_back(beginWord);

        int wordLength = beginWord.length();

        // -------------------------------
        // STEP 1: Build pattern mappings
        // -------------------------------
        for (string word : wordList)
        {
            for (int i = 0; i < wordLength; i++)
            {

                // Replace one character with '*'
                // Example: hot -> h*t
                string pattern = word;
                pattern[i] = '*';

                // Store word under this pattern
                patternMap[pattern].push_back(word);
            }
        }

        // -------------------------------
        // STEP 2: BFS Initialization
        // -------------------------------
        queue<pair<string, int>> q; // {currentWord, currentLevel}
        unordered_set<string> visited;

        // Start BFS from beginWord at level 1
        q.push({beginWord, 1});
        visited.insert(beginWord);

        // -------------------------------
        // STEP 3: BFS Traversal
        // -------------------------------
        while (!q.empty())
        {

            auto [currentWord, level] = q.front();
            q.pop();

            // If we reach endWord, return transformation length
            if (currentWord == endWord)
                return level;

            // Generate all possible patterns for currentWord
            for (int i = 0; i < wordLength; i++)
            {
                string pattern = currentWord;
                pattern[i] = '*';

                // Traverse all words that match this pattern
                for (string nextWord : patternMap[pattern])
                {

                    // Visit unvisited words only
                    if (!visited.count(nextWord))
                    {
                        visited.insert(nextWord);
                        q.push({nextWord, level + 1});
                    }
                }
            }
        }

        // If endWord is unreachable
        return 0;
    }
};




// char replacement approach

class Solution {
    public:
        int wordLadderLength(string startWord, string targetWord, vector<string>& wordList) {
    
            // Queue to perform BFS
            // Stores pairs of (current_word, number_of_steps_taken)
            queue<pair<string, int>> q;
    
            // Start BFS from the startWord with step count = 1
            q.push({startWord, 1});
    
            // Store all words in a set for:
            // 1. Fast lookup (O(log N))
            // 2. Easy removal to avoid revisiting
            set<string> st(wordList.begin(), wordList.end());
    
            // Remove startWord if it exists in the set
            // This prevents going back to the start word again
            st.erase(startWord);
    
            // BFS traversal
            while (!q.empty()) {
    
                // Get the front element of the queue
                string word = q.front().first;
                int steps = q.front().second;
                q.pop();
    
                // If we reach the target word, return the steps
                // BFS guarantees this is the shortest path
                if (word == targetWord)
                    return steps;
    
                // Try changing each character of the current word
                for (int i = 0; i < word.size(); i++) {
    
                    // Store original character to restore later
                    char original = word[i];
    
                    // Try all possible characters from 'a' to 'z'
                    for (char ch = 'a'; ch <= 'z'; ch++) {
                        word[i] = ch;
    
                        // If the transformed word exists in the dictionary
                        if (st.find(word) != st.end()) {
    
                            // Remove it from the set to avoid revisiting
                            st.erase(word);
    
                            // Push the new word into the queue
                            // Increase the step count by 1
                            q.push({word, steps + 1});
                        }
                    }
    
                    // Restore the original character
                    word[i] = original;
                }
            }
    
            // If no transformation sequence exists
            return 0;
        }
    };
    
