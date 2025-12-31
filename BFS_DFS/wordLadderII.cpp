// word ladder 2
// leetcode 126

class Solution
{
public:
    vector<vector<string>> findLadders(string beginWord, string endWord, vector<string> &wordList)
    {

        // dist[word] = shortest distance of 'word' from beginWord
        unordered_map<string, int> dist;

        // parent[word] = list of words from which we can reach 'word'
        // using the shortest distance
        unordered_map<string, vector<string>> parent;

        // BFS queue stores only words (not full paths)
        queue<string> q;
        q.push(beginWord);

        // Initialize distance of all dictionary words as infinity
        for (auto it : wordList)
        {
            dist[it] = INT_MAX;
        }

        // Distance of beginWord from itself is 0
        dist[beginWord] = 0;

        // ---------------- BFS PHASE ----------------
        while (!q.empty())
        {

            string word = q.front();
            q.pop();

            // Try changing every character of current word
            for (int i = 0; i < word.size(); i++)
            {

                for (char c = 'a'; c <= 'z'; c++)
                {

                    // Generate next possible word
                    string nxtword = word;
                    nxtword[i] = c;

                    // Check if the generated word exists in dictionary
                    if (dist.find(nxtword) != dist.end())
                    {

                        // Case 1: Found a shorter path to nxtword
                        if (dist[nxtword] > dist[word] + 1)
                        {

                            // Update distance
                            dist[nxtword] = dist[word] + 1;

                            // Push word into BFS queue
                            q.push(nxtword);

                            // Clear old parents (they were longer paths)
                            parent[nxtword].clear();

                            // Current word becomes the parent
                            parent[nxtword].push_back(word);
                        }

                        // Case 2: Found another shortest path
                        else if (dist[nxtword] == dist[word] + 1)
                        {

                            // Add current word as another valid parent
                            parent[nxtword].push_back(word);
                        }
                    }
                }
            }
        }

        // ---------------- BACKTRACKING PHASE ----------------
        vector<vector<string>> res; // Final result
        vector<string> path;        // Current path

        // Start backtracking from endWord
        path.push_back(endWord);
        backtrack(parent, endWord, res, path, beginWord);

        return res;
    }

    // DFS backtracking to generate all shortest paths
    void backtrack(
        unordered_map<string, vector<string>> &parent,
        string node,
        vector<vector<string>> &res,
        vector<string> &path,
        string beginWord)
    {

        // Base case: reached beginWord
        if (node == beginWord)
        {

            // Reverse path (because we built it from end → begin)
            vector<string> temp = path;
            reverse(temp.begin(), temp.end());

            // Store valid transformation sequence
            res.push_back(temp);
            return;
        }

        // Explore all parents of current node
        for (string &p : parent[node])
        {

            // Choose
            path.push_back(p);

            // Explore
            backtrack(parent, p, res, path, beginWord);

            // Un-choose (backtrack)
            path.pop_back();
        }
    }
};
