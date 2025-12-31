int getCelebrity(vector<vector<int>> arr)
{
    // Number of people at the party
    int n = arr.size();

    // Stack to keep track of celebrity candidates
    stack<int> s;

    // Step 1: Push all people (0 to n-1) into the stack
    // Initially, everyone is a potential celebrity
    for (int i = 0; i < n; i++)
    {
        s.push(i);
    }

    // Step 2: Eliminate non-celebrities
    // Compare two people at a time
    while (s.size() > 1)
    {
        int i = s.top(); // First person
        s.pop();

        int j = s.top(); // Second person
        s.pop();

        // If i does NOT know j, then j cannot be a celebrity
        // because a celebrity is known by everyone
        if (arr[i][j] == 0)
        {
            s.push(i); // i might be a celebrity
        }
        // If i knows j, then i cannot be a celebrity
        // because a celebrity knows nobody
        else
        {
            s.push(j); // j might be a celebrity
        }
    }

    // Step 3: Potential celebrity left in the stack
    int celeb = s.top();

    // Step 4: Verify the candidate
    for (int i = 0; i < n; i++)
    {
        // Conditions for a valid celebrity:
        // 1. Everyone else must know the celebrity -> arr[i][celeb] == 1
        // 2. Celebrity must know nobody -> arr[celeb][i] == 0
        if (i != celeb && (arr[i][celeb] == 0 || arr[celeb][i] == 1))
        {
            return -1; // No celebrity exists
        }
    }

    // If verification passes, return celebrity index
    return celeb;
}
