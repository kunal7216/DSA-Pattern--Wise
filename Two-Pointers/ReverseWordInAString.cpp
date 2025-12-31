class Solution
{
public:
    string reverseWords(string s)
    {

        // Create a stringstream object to break the string into words
        // It automatically ignores extra spaces
        stringstream ss(s);

        string word;          // Stores one word at a time
        vector<string> words; // Stores all extracted words

        // Extract words from the string one by one
        while (ss >> word)
        {
            words.push_back(word); // Store each word in the vector
        }

        string res; // Result string

        // Traverse the words vector from the end to the beginning
        // This reverses the order of words
        for (int i = words.size() - 1; i >= 0; i--)
        {
            res += words[i]; // Append the current word

            // Add a space after each word except the last one
            if (i != 0)
            {
                res += " ";
            }
        }

        // Return the final string with words reversed
        return res;
    }
};
