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


***********************************************************Brute solution************************************************************************************
    #include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<vector<string>> result;
    int minLen = INT_MAX;

    bool oneDiff(string &a, string &b) {
        int diff = 0;

        for (int i = 0; i < a.size(); i++) {
            if (a[i] != b[i]) diff++;
        }

        return diff == 1;
    }

    void dfs(string current,
             string &endWord,
             vector<string> &wordList,
             unordered_set<string> &visited,
             vector<string> &path) {
        
        if (path.size() > minLen) return;

        if (current == endWord) {
            if (path.size() < minLen) {
                minLen = path.size();
                result.clear();
            }

            result.push_back(path);
            return;
        }

        for (string &word : wordList) {
            if (!visited.count(word) && oneDiff(current, word)) {
                visited.insert(word);
                path.push_back(word);

                dfs(word, endWord, wordList, visited, path);

                path.pop_back();
                visited.erase(word);
            }
        }
    }

    vector<vector<string>> findLadders(string beginWord,
                                       string endWord,
                                       vector<string>& wordList) {
        
        unordered_set<string> wordSet(wordList.begin(), wordList.end());

        if (!wordSet.count(endWord)) return {};

        unordered_set<string> visited;
        vector<string> path;

        visited.insert(beginWord);
        path.push_back(beginWord);

        dfs(beginWord, endWord, wordList, visited, path);

        return result;
    }
};
***********************************************************Better solution************************************************************************************
    #include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<vector<string>> findLadders(string beginWord,
                                       string endWord,
                                       vector<string>& wordList) {
        
        unordered_set<string> wordSet(wordList.begin(), wordList.end());

        if (!wordSet.count(endWord)) return {};

        vector<vector<string>> result;

        queue<vector<string>> q;
        q.push({beginWord});

        unordered_set<string> visited;
        visited.insert(beginWord);

        bool found = false;

        while (!q.empty() && !found) {
            int size = q.size();
            unordered_set<string> levelVisited;

            for (int i = 0; i < size; i++) {
                vector<string> path = q.front();
                q.pop();

                string word = path.back();

                for (int pos = 0; pos < word.size(); pos++) {
                    char original = word[pos];

                    for (char ch = 'a'; ch <= 'z'; ch++) {
                        if (ch == original) continue;

                        word[pos] = ch;

                        if (wordSet.count(word) && !visited.count(word)) {
                            vector<string> newPath = path;
                            newPath.push_back(word);

                            if (word == endWord) {
                                found = true;
                                result.push_back(newPath);
                            } else {
                                q.push(newPath);
                            }

                            levelVisited.insert(word);
                        }
                    }

                    word[pos] = original;
                }
            }

            for (string word : levelVisited) {
                visited.insert(word);
            }
        }

        return result;
    }
};
***********************************************************Optimal solution************************************************************************************



class Solution {
public:
    vector<vector<string>> result;
    unordered_map<string, vector<string>> parent;

    void backtrack(string word,
                   string &beginWord,
                   vector<string> &path) {
        
        if (word == beginWord) {
            vector<string> temp = path;
            reverse(temp.begin(), temp.end());
            result.push_back(temp);
            return;
        }

        for (string par : parent[word]) {
            path.push_back(par);
            backtrack(par, beginWord, path);
            path.pop_back();
        }
    }

    vector<vector<string>> findLadders(string beginWord,
                                       string endWord,
                                       vector<string>& wordList) {
        
        unordered_set<string> wordSet(wordList.begin(), wordList.end());

        if (!wordSet.count(endWord)) return {};

        queue<string> q;
        q.push(beginWord);

        unordered_map<string, int> dist;
        dist[beginWord] = 0;

        bool found = false;
        int wordLength = beginWord.size();

        while (!q.empty() && !found) {
            int size = q.size();

            for (int i = 0; i < size; i++) {
                string word = q.front();
                q.pop();

                int currentDist = dist[word];

                for (int pos = 0; pos < wordLength; pos++) {
                    string temp = word;

                    for (char ch = 'a'; ch <= 'z'; ch++) {
                        if (temp[pos] == ch) continue;

                        temp[pos] = ch;

                        if (!wordSet.count(temp)) continue;

                        if (!dist.count(temp)) {
                            dist[temp] = currentDist + 1;
                            parent[temp].push_back(word);
                            q.push(temp);
                        } 
                        else if (dist[temp] == currentDist + 1) {
                            parent[temp].push_back(word);
                        }

                        if (temp == endWord) {
                            found = true;
                        }
                    }
                }
            }
        }

        if (!dist.count(endWord)) return {};

        vector<string> path;
        path.push_back(endWord);

        backtrack(endWord, beginWord, path);

        return result;
    }
};
    
