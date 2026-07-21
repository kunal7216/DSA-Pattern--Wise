// Design Add and Search Words Data Structure
// LeetCode Problem 211
// https://leetcode.com/problems/design-add-and-search-words-data-structure/

/*
-------------------------------------------------------
Approach 1 : Brute Force

Idea:
Store every inserted word inside a vector.

Whenever search() is called:
1. Compare the given pattern with every stored word.
2. Skip words having different lengths.
3. Compare character by character.
4. '.' matches any character.

Time Complexity:
addWord() : O(1)
search()  : O(N × L)

N = Number of stored words
L = Length of word

Space Complexity:
O(Total Characters Stored)
-------------------------------------------------------
*/

class WordDictionary {
private:
    vector<string> words;

public:

    // Constructor
    WordDictionary() {

    }

    // Simply store the word
    void addWord(string word) {
        words.push_back(word);
    }

    bool search(string word) {

        // Compare with every stored word
        for (string &current : words) {

            // Length must be same
            if (current.size() != word.size())
                continue;

            bool match = true;

            // Compare each character
            for (int i = 0; i < word.size(); i++) {

                // '.' can match anything
                if (word[i] != '.' && word[i] != current[i]) {
                    match = false;
                    break;
                }
            }

            // Found matching word
            if (match)
                return true;
        }

        return false;
    }
};

/*
-------------------------------------------------------
Approach 2 : Better

Idea:
Store words according to their length.

Example:

Length 3 -> bad dad mad
Length 5 -> apple hello

During search:
Only compare with words having the same length.

Time Complexity:
addWord() : O(1)
search()  : O(K × L)

K = Number of words having same length
L = Word Length

Space Complexity:
O(Total Characters Stored)
-------------------------------------------------------
*/

class WordDictionary {

private:

    // Key = Length of word
    // Value = List of words having that length
    unordered_map<int, vector<string>> mp;

public:

    WordDictionary() {

    }

    // Store word according to its length
    void addWord(string word) {

        mp[word.size()].push_back(word);
    }

    bool search(string word) {

        // Only check words having same length
        for (string &current : mp[word.size()]) {

            bool match = true;

            for (int i = 0; i < word.size(); i++) {

                // '.' matches every character
                if (word[i] != '.' && word[i] != current[i]) {

                    match = false;
                    break;
                }
            }

            if (match)
                return true;
        }

        return false;
    }
};

/*
-------------------------------------------------------
Approach 3 : Trie + DFS (Optimal)

Idea:
Use Trie to store words efficiently.

Insertion:
Insert every character into Trie.

Searching:

Case 1:
Normal character
-> Move to corresponding child.

Case 2:
'.'
-> Try all 26 children using DFS.

If any path succeeds,
return true.

Time Complexity:

addWord() : O(L)

search()

Best Case:
O(L)

Worst Case:
O(26^L)
(When every character is '.')

Space Complexity:

O(Total Characters Inserted)
-------------------------------------------------------
*/

class TrieNode {

public:

    // 26 lowercase letters
    TrieNode* children[26];

    // Marks end of word
    bool isEnd;

    TrieNode() {

        isEnd =false;

        // Initially every child is NULL
        for(int i=0;i<26;i++)
            children[i]=nullptr;
    }
};

class WordDictionary {

private:

    TrieNode* root;

    /*
    DFS Search

    index = Current position in search word
    node = Current Trie node
    */

    bool dfs(string &word,int index,TrieNode* node){

        // Entire pattern processed
        if(index==word.size())
            return node->isEnd;

        char ch=word[index];

        // Wildcard found
        if(ch=='.'){

            // Explore every child
            for(int i=0;i<26;i++){

                if(node->children[i]!=nullptr){

                    // If any child returns true,
                    // answer is true
                    if(dfs(word,index+1,node->children[i]))
                        return true;
                }
            }

            // No path matched
            return false;
        }

        // Normal character

        int idx=ch-'a';

        // Character not present
        if(node->children[idx]==nullptr)
            return false;

        // Continue search
        return dfs(word,index+1,node->children[idx]);
    }

public:

    WordDictionary() {

        root=new TrieNode();
    }

    /*
    Insert word into Trie

    Time : O(L)
    */

    void addWord(string word) {

        TrieNode* current=root;

        for(char ch:word){

            int idx=ch-'a';

            // Create node if absent
            if(current->children[idx]==nullptr)
                current->children[idx]=new TrieNode();

            // Move ahead
            current=current->children[idx];
        }

        // Mark end of word
        current->isEnd=true;
    }

    /*
    Search word

    '.' matches any one character.
    */

    bool search(string word) {

        return dfs(word,0,root);
    }
};

/*
Example

WordDictionary obj;

obj.addWord("bad");
obj.addWord("dad");
obj.addWord("mad");

obj.search("bad");   // true
obj.search(".ad");   // true
obj.search("b..");   // true
obj.search("pad");   // false
*/
