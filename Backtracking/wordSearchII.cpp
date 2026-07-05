// word search II
// link: https://leetcode.com/problems/word-search-ii/
// leetcode 212


// Brute force --- without visited matrix using simple DFS
class Solution {
public:
    bool dfs(vector<vector<char>>& board, string &word,
             int i, int j, int index) {

        if(index == word.size())
            return true;

        if(i<0 || j<0 || i>=board.size() || j>=board[0].size())
            return false;

        if(board[i][j] != word[index])
            return false;

        char temp = board[i][j];
        board[i][j] = '#';

        bool found =
            dfs(board, word, i+1, j, index+1) ||
            dfs(board, word, i-1, j, index+1) ||
            dfs(board, word, i, j+1, index+1) ||
            dfs(board, word, i, j-1, index+1);

        board[i][j] = temp;

        return found;
    }

    bool exist(vector<vector<char>>& board, string word) {

        int m = board.size();
        int n = board[0].size();

        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(dfs(board, word, i, j, 0))
                    return true;
            }
        }

        return false;
    }

    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {

        vector<string> ans;

        for(string &word : words){
            if(exist(board, word))
                ans.push_back(word);
        }

        return ans;
    }
};



// Better Solution
class Solution {
public:
    unordered_set<string> dict;
    unordered_set<string> ans;

    void dfs(vector<vector<char>>& board,
             int i, int j,
             string &path) {

        if(i<0 || j<0 || i>=board.size() || j>=board[0].size())
            return;

        if(board[i][j]=='#')
            return;

        path.push_back(board[i][j]);

        if(dict.count(path))
            ans.insert(path);

        char temp = board[i][j];
        board[i][j] = '#';

        dfs(board,i+1,j,path);
        dfs(board,i-1,j,path);
        dfs(board,i,j+1,path);
        dfs(board,i,j-1,path);

        board[i][j]=temp;
        path.pop_back();
    }

    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {

        for(string &w:words)
            dict.insert(w);

        string path;

        for(int i=0;i<board.size();i++)
            for(int j=0;j<board[0].size();j++)
                dfs(board,i,j,path);

        return vector<string>(ans.begin(),ans.end());
    }
};


// Optimal solution -- Trie + DFS


class Solution {
public:
    TrieNode* root = new TrieNode();

    void insert(string word) {
        TrieNode* node = root;

        for (char c : word) {
            int idx = c - 'a';

            if (!node->children[idx])
                node->children[idx] = new TrieNode();

            node = node->children[idx];
        }

        node->word = word;
    }

    void dfs(vector<vector<char>>& board,
             int i, int j,
             TrieNode* node,
             vector<string>& ans) {

        char c = board[i][j];

        if (c == '#')
            return;

        if (!node->children[c - 'a'])
            return;

        node = node->children[c - 'a'];

        if (!node->word.empty()) {
            ans.push_back(node->word);
            node->word = "";
        }

        board[i][j] = '#';

        int dir[4][2]={{1,0},{-1,0},{0,1},{0,-1}};

        for(auto &d:dir){

            int x=i+d[0];
            int y=j+d[1];

            if(x>=0 && y>=0 &&
               x<board.size() &&
               y<board[0].size()){

                dfs(board,x,y,node,ans);
            }
        }

        board[i][j]=c;
    }

    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {

        for(string &word:words)
            insert(word);

        vector<string> ans;

        for(int i=0;i<board.size();i++)
            for(int j=0;j<board[0].size();j++)
                dfs(board,i,j,root,ans);

        return ans;
    }
};
