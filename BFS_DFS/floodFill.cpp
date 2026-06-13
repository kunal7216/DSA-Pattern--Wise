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

*************************************************************Brute Solution***********************************************************************************
    class Solution {
public:
    int m, n;
    vector<vector<int>> directions = {{-1,0}, {1,0}, {0,-1}, {0,1}};

    bool canReach(vector<vector<int>>& image, int sr, int sc, int targetR, int targetC, int originalColor) {
        vector<vector<int>> visited(m, vector<int>(n, 0));
        queue<pair<int, int>> q;

        q.push({sr, sc});
        visited[sr][sc] = 1;

        while (!q.empty()) {
            auto [r, c] = q.front();
            q.pop();

            if (r == targetR && c == targetC) {
                return true;
            }

            for (auto &dir : directions) {
                int nr = r + dir[0];
                int nc = c + dir[1];

                if (nr >= 0 && nr < m && nc >= 0 && nc < n &&
                    !visited[nr][nc] &&
                    image[nr][nc] == originalColor) {
                    
                    visited[nr][nc] = 1;
                    q.push({nr, nc});
                }
            }
        }

        return false;
    }

    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        m = image.size();
        n = image[0].size();

        int originalColor = image[sr][sc];

        if (originalColor == color) {
            return image;
        }

        vector<vector<int>> result = image;

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (image[i][j] == originalColor &&
                    canReach(image, sr, sc, i, j, originalColor)) {
                    result[i][j] = color;
                }
            }
        }

        return result;
    }
};
*************************************************************Better Solution****************************************************************************************
    class Solution {
public:
    int m, n;
    int originalColor;
    vector<vector<int>> directions = {{-1,0}, {1,0}, {0,-1}, {0,1}};

    void dfs(vector<vector<int>>& image, vector<vector<int>>& visited, int r, int c, int newColor) {
        // Boundary check
        if (r < 0 || r >= m || c < 0 || c >= n) {
            return;
        }

        // Already visited
        if (visited[r][c]) {
            return;
        }

        // Only cells with original color can be filled
        if (image[r][c] != originalColor) {
            return;
        }

        visited[r][c] = 1;
        image[r][c] = newColor;

        // Visit 4-directionally connected cells
        for (auto &dir : directions) {
            int nr = r + dir[0];
            int nc = c + dir[1];

            dfs(image, visited, nr, nc, newColor);
        }
    }

    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        m = image.size();
        n = image[0].size();

        originalColor = image[sr][sc];

        if (originalColor == color) {
            return image;
        }

        vector<vector<int>> visited(m, vector<int>(n, 0));

        dfs(image, visited, sr, sc, color);

        return image;
    }
};
*************************************************************Optimal Solution****************************************************************************************
    class Solution {
public:
    int m, n;
    int originalColor;
    vector<vector<int>> directions = {{-1,0}, {1,0}, {0,-1}, {0,1}};

    void dfs(vector<vector<int>>& image, int r, int c, int newColor) {
        // Check boundary
        if (r < 0 || r >= m || c < 0 || c >= n) {
            return;
        }

        // If cell does not have original color, do not fill it
        if (image[r][c] != originalColor) {
            return;
        }

        // Fill current cell
        image[r][c] = newColor;

        // Move in 4 directions
        for (auto &dir : directions) {
            int nr = r + dir[0];
            int nc = c + dir[1];

            dfs(image, nr, nc, newColor);
        }
    }

    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        m = image.size();
        n = image[0].size();

        originalColor = image[sr][sc];

        // Important edge case:
        // If original color and new color are same,
        // DFS will go into infinite recursion.
        if (originalColor == color) {
            return image;
        }

        dfs(image, sr, sc, color);

        return image;
    }
};
