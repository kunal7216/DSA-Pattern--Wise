class Solution
{
private:
    // DFS function to fill connected pixels
    void dfs(int row, int col,
             vector<vector<int>> &image,
             int newColor,
             int iniColor,
             int delRow[],
             int delCol[])
    {

        // Change the color of the current pixel
        image[row][col] = newColor;

        int n = image.size();    // Number of rows
        int m = image[0].size(); // Number of columns

        // Explore all 4 possible directions
        for (int i = 0; i < 4; i++)
        {
            int nrow = row + delRow[i];
            int ncol = col + delCol[i];

            // Check:
            // 1. Inside grid boundaries
            // 2. Pixel has the same initial color
            if (nrow >= 0 && nrow < n &&
                ncol >= 0 && ncol < m &&
                image[nrow][ncol] == iniColor)
            {

                // Recursively fill the connected pixel
                dfs(nrow, ncol, image, newColor, iniColor, delRow, delCol);
            }
        }
    }

public:
    vector<vector<int>> floodFill(vector<vector<int>> &image,
                                  int sr, int sc,
                                  int newColor)
    {

        int iniColor = image[sr][sc];

        // Edge case:
        // If initial color is same as newColor, no need to process
        if (iniColor == newColor)
            return image;

        // Direction vectors: Up, Right, Down, Left
        int delRow[] = {-1, 0, +1, 0};
        int delCol[] = {0, +1, 0, -1};

        // Start DFS from the source pixel
        dfs(sr, sc, image, newColor, iniColor, delRow, delCol);

        return image;
    }
};
