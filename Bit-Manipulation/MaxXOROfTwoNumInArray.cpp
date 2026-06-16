// Max xor of two numbers in an array
// Time Complexity: O(N*32) where N is the number of elements in the array
// Space Complexity: O(1)
// leetcode problem link: https://leetcode.com/problems/maximum-xor-of-two-numbers-in-an-array/

*********************************************************Brute Solution*********************************************************************************************
    class Solution {
public:
    int findMaximumXOR(vector<int>& nums) {

        int maxi = 0;
        int n = nums.size();

        // Try every pair
        for (int i = 0; i < n; i++) {

            for (int j = i + 1; j < n; j++) {

                int currXor = nums[i] ^ nums[j];

                maxi = max(maxi, currXor);
            }
        }

        return maxi;
    }
};
*********************************************************Better Solution*********************************************************************************************
    class Solution {
public:
    int findMaximumXOR(vector<int>& nums) {

        int maxXor = 0;
        int mask = 0;

        // Check bits from MSB to LSB
        for (int bit = 31; bit >= 0; bit--) {

            mask |= (1 << bit);

            unordered_set<int> prefixes;

            // Store prefixes
            for (int num : nums) {
                prefixes.insert(num & mask);
            }

            // Try setting current bit to 1
            int candidate = maxXor | (1 << bit);

            bool found = false;

            for (int prefix : prefixes) {

                if (prefixes.count(prefix ^ candidate)) {
                    found = true;
                    break;
                }
            }

            // If possible, keep bit = 1
            if (found) {
                maxXor = candidate;
            }
        }

        return maxXor;
    }
};
*********************************************************Optimal SOlution*********************************************************************************************
    class TrieNode {
public:
    TrieNode* children[2];

    TrieNode() {
        children[0] = nullptr;
        children[1] = nullptr;
    }
};

class Trie {
public:
    TrieNode* root;

    Trie() {
        root = new TrieNode();
    }

    // Insert number into trie
    void insert(int num) {

        TrieNode* node = root;

        // Store bits from MSB to LSB
        for (int i = 31; i >= 0; i--) {

            int bit = (num >> i) & 1;

            if (node->children[bit] == nullptr) {
                node->children[bit] = new TrieNode();
            }

            node = node->children[bit];
        }
    }

    // Find maximum XOR for num
    int getMaxXor(int num) {

        TrieNode* node = root;
        int maxXor = 0;

        for (int i = 31; i >= 0; i--) {

            int bit = (num >> i) & 1;

            // Opposite bit preferred
            int oppositeBit = 1 - bit;

            if (node->children[oppositeBit]) {

                // Set ith bit in answer
                maxXor |= (1 << i);

                node = node->children[oppositeBit];

            } else {

                node = node->children[bit];
            }
        }

        return maxXor;
    }
};

class Solution {
public:
    int findMaximumXOR(vector<int>& nums) {

        Trie trie;

        // Insert all numbers
        for (int num : nums) {
            trie.insert(num);
        }

        int ans = 0;

        // Find best XOR for every number
        for (int num : nums) {

            ans = max(ans, trie.getMaxXor(num));
        }

        return ans;
    }
};
