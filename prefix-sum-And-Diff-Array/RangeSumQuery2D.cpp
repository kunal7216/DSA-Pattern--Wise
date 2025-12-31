class NumMatrix
{
private:
    // 2D prefix sum matrix
    // prefix[i][j] stores sum of all elements from (0,0) to (i,j)
    vector<vector<int>> prefix;

public:
    // Constructor: builds the 2D prefix sum matrix
    NumMatrix(vector<vector<int>> &matrix)
    {

        // If matrix is empty, do nothing
        if (matrix.empty() || matrix[0].empty())
            return;

        int m = matrix.size();    // number of rows
        int n = matrix[0].size(); // number of columns

        // Initialize prefix matrix with zeros
        prefix.assign(m, vector<int>(n, 0));

        // Build the prefix sum matrix
        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {

                // Sum from the cell directly above
                int top = (i > 0) ? prefix[i - 1][j] : 0;

                // Sum from the cell directly to the left
                int left = (j > 0) ? prefix[i][j - 1] : 0;

                // Sum from the diagonal top-left cell
                // (this area gets counted twice, so we subtract it)
                int topLeft = (i > 0 && j > 0) ? prefix[i - 1][j - 1] : 0;

                // Current prefix sum using inclusion-exclusion principle
                prefix[i][j] = matrix[i][j] + top + left - topLeft;
            }
        }
    }

    // Returns sum of elements inside rectangle
    // (row1, col1) to (row2, col2)
    int sumRegion(int row1, int col1, int row2, int col2)
    {

        // Total sum from (0,0) to (row2,col2)
        int total = prefix[row2][col2];

        // Area above the rectangle
        int top = (row1 > 0) ? prefix[row1 - 1][col2] : 0;

        // Area to the left of the rectangle
        int left = (col1 > 0) ? prefix[row2][col1 - 1] : 0;

        // Area counted twice (top-left overlap)
        int topLeft = (row1 > 0 && col1 > 0)
                          ? prefix[row1 - 1][col1 - 1]
                          : 0;

        // Final submatrix sum using inclusion-exclusion
        return total - top - left + topLeft;
    }
};
