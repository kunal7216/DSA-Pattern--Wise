// Max xor of two numbers in an array
// Time Complexity: O(N*32) where N is the number of elements in the array
// Space Complexity: O(1)
// leetcode problem link: https://leetcode.com/problems/maximum-xor-of-two-numbers-in-an-array/

// Trie node structure for storing binary representation of numbers
struct trie
{
    // Each node has two possible children: 0 and 1
    trie *next[2];

    // Constructor initializes both children as NULL
    trie()
    {
        next[0] = NULL;
        next[1] = NULL;
    }
};

// Trie wrapper class to handle insert and query operations
class TrieNode
{
private:
    trie *root; // Root of the binary trie

public:
    // Constructor initializes the root node
    TrieNode()
    {
        root = new trie();
    }

    // Inserts a number into the trie (bit by bit from MSB to LSB)
    void insert(int num)
    {
        trie *curr = root;

        // Traverse from the most significant bit (31) to least (0)
        for (int i = 31; i >= 0; i--)
        {
            // Extract the i-th bit of the number
            int bit = (num >> i) & 1;

            // If the corresponding child does not exist, create it
            if (curr->next[bit] == NULL)
            {
                curr->next[bit] = new trie();
            }

            // Move to the next node
            curr = curr->next[bit];
        }
    }

    // Finds the maximum XOR value achievable with 'num'
    int max_xor(int num)
    {
        trie *curr = root;
        int ans = 0;

        // Traverse the trie from MSB to LSB
        for (int i = 31; i >= 0; i--)
        {
            // Extract the current bit of num
            int bit = (num >> i) & 1;

            /*
             To maximize XOR:
             - Prefer the opposite bit (!bit) if it exists
             - This makes the current XOR bit = 1
            */
            if (curr->next[!bit])
            {
                ans += (1 << i); // Set the i-th bit in the answer
                curr = curr->next[!bit];
            }
            else
            {
                // Otherwise, follow the same bit path
                curr = curr->next[bit];
            }
        }

        // Return the maximum XOR value for this number
        return ans;
    }
};

// Main solution class
class Solution
{
public:
    int findMaximumXOR(vector<int> &nums)
    {
        int max_ans = 0;
        int n = nums.size();

        // Create a Trie to store numbers in binary form
        TrieNode *t = new TrieNode();

        /*
         Insert each number into the trie and
         simultaneously compute the maximum XOR
         achievable with numbers already inserted
        */
        for (int i = 0; i < n; i++)
        {
            t->insert(nums[i]);
            max_ans = max(max_ans, t->max_xor(nums[i]));
        }

        // Return the maximum XOR found
        return max_ans;
    }
};
