class Solution {
public:
    vector<vector<int>> dp;

    int ftd(int sr, int sc, int er, int ec, vector<vector<int>>& arr) {
        // Base cases
        if (sr > er || sc > ec) return 0;   // Out of bounds
        if (arr[sr][sc] == -2) return 0;     // Obstacle
        if (sr == er && sc == ec) return 1;  // Reached destination

        // If already computed, return the stored result
        if (dp[sr][sc] != -1) return dp[sr][sc];

        // Recursive case: move right and down
        return dp[sr][sc] = ftd(sr, sc + 1, er, ec, arr) + ftd(sr + 1, sc, er, ec, arr);
    }

    int uniquePathsWithObstacles(vector<vector<int>>& arr) {
        int m = arr.size(), n = arr[0].size();
        dp.resize(m, vector<int>(n, -1));

        // Update arr to mark obstacles as -2 (instead of 1)
        for (auto& row : arr) {
            for (int& x : row) {
                if (x == 1) x = -2;  // Mark obstacles
            }
        }

        // Start the recursion from (0, 0) to (m-1, n-1)
        return ftd(0, 0, m - 1, n - 1, arr);
    }
};
