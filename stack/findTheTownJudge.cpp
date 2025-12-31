class Solution
{
public:
    int findJudge(int N, vector<vector<int>> &trust)
    {

        // output[i] will store:
        // (number of people who trust i) - (number of people i trusts)
        vector<int> output(N + 1, 0);

        // Process each trust relationship
        for (int i = 0; i < trust.size(); i++)
        {

            // trust[i][0] trusts someone → cannot be judge
            // so decrease its score
            output[trust[i][0]]--;

            // trust[i][1] is trusted by someone
            // so increase its score
            output[trust[i][1]]++;
        }

        // A town judge must:
        // 1) Be trusted by N-1 people  → + (N-1)
        // 2) Trust nobody              → - 0
        // Net value should be N-1
        for (int j = 1; j <= N; j++)
        {
            if (output[j] == N - 1)
                return j; // Found the town judge
        }

        // If no such person exists
        return -1;
    }
};
