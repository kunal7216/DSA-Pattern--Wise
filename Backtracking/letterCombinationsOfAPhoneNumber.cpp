// letter Combinations Of A Phone Number
// leetcode: https://leetcode.com/problems/letter-combinations-of-a-phone-number/
// leetcode - 17

class Solution
{
public:
    vector<string> letterCombinations(string digits)
    {
        vector<string> res;

        // If input is empty, there are no combinations
        if (digits.empty())
        {
            return res;
        }

        // Mapping of digits to corresponding letters on a phone keypad
        unordered_map<char, string> digitToLetters = {
            {'2', "abc"},
            {'3', "def"},
            {'4', "ghi"},
            {'5', "jkl"},
            {'6', "mno"},
            {'7', "pqrs"},
            {'8', "tuv"},
            {'9', "wxyz"}};

        // Start backtracking from index 0 with an empty combination
        backtrack(digits, 0, "", res, digitToLetters);

        return res;
    }

    // Recursive backtracking function
    void backtrack(const string &digits,
                   int idx,
                   string comb,
                   vector<string> &res,
                   const unordered_map<char, string> &digitToLetters)
    {

        // Base case: if current index equals length of digits,
        // a complete combination has been formed
        if (idx == digits.length())
        {
            res.push_back(comb);
            return;
        }

        // Get the letters corresponding to the current digit
        string letters = digitToLetters.at(digits[idx]);

        // Try each letter and move to the next digit
        for (char letter : letters)
        {
            backtrack(digits, idx + 1, comb + letter, res, digitToLetters);
        }
    }
};
