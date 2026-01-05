// pallindrome partitioning
// leetcode: https://leetcode.com/problems/palindrome-partitioning/
// leetcode - 131

class Solution
{
public:
    // Function to check if a string is palindrome
    bool isPalin(string s)
    {
        string s2 = s;
        reverse(s2.begin(), s2.end());
        return s == s2;
    }

    // Backtracking function to generate all palindrome partitions
    void getAllParts(string s, vector<string> &partitions, vector<vector<string>> &ans)
    {
        // Base case: if string is empty, store current partition
        if (s.size() == 0)
        {
            ans.push_back(partitions);
            return;
        }

        // Try all possible prefixes
        for (int i = 0; i < s.size(); i++)
        {
            string part = s.substr(0, i + 1);

            // If prefix is palindrome, proceed recursively
            if (isPalin(part))
            {
                partitions.push_back(part);
                getAllParts(s.substr(i + 1), partitions, ans);
                partitions.pop_back(); // backtrack
            }
        }
    }

    // Main function
    vector<vector<string>> partition(string s)
    {
        vector<vector<string>> ans;
        vector<string> partitions;

        getAllParts(s, partitions, ans);
        return ans;
    }
};
