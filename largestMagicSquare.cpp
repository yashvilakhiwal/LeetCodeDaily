class Solution {
public:
    int largestMagicSquare(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        vector<vector<int>> rowPrefix(m, vector<int>(n + 1, 0));
        vector<vector<int>> colPrefix(m + 1, vector<int>(n, 0));
        
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                rowPrefix[i][j + 1] = rowPrefix[i][j] + grid[i][j];
            }
        }
        
        for (int j = 0; j < n; j++) {
            for (int i = 0; i < m; i++) {
                colPrefix[i + 1][j] = colPrefix[i][j] + grid[i][j];
            }
        }
        
        int maxSize = min(m, n);
        for (int k = maxSize; k >= 1; k--) {
            for (int i = 0; i <= m - k; i++) {
                for (int j = 0; j <= n - k; j++) {
                    if (isMagicSquare(grid, rowPrefix, colPrefix, i, j, k)) {
                        return k;
                    }
                }
            }
        }
        
        return 1;
    }
    
private:
    bool isMagicSquare(vector<vector<int>>& grid, 
                       vector<vector<int>>& rowPrefix,
                       vector<vector<int>>& colPrefix,
                       int startRow, int startCol, int k) {
        int expectedSum = rowPrefix[startRow][startCol + k] - rowPrefix[startRow][startCol];
        
        for (int i = startRow; i < startRow + k; i++) {
            int rowSum = rowPrefix[i][startCol + k] - rowPrefix[i][startCol];
            if (rowSum != expectedSum) {
                return false;
            }
        }
        
        for (int j = startCol; j < startCol + k; j++) {
            int colSum = colPrefix[startRow + k][j] - colPrefix[startRow][j];
            if (colSum != expectedSum) {
                return false;
            }
        }
        
        int diag1Sum = 0;
        for (int d = 0; d < k; d++) {
            diag1Sum += grid[startRow + d][startCol + d];
        }
        if (diag1Sum != expectedSum) {
            return false;
        }
        
        int diag2Sum = 0;
        for (int d = 0; d < k; d++) {
            diag2Sum += grid[startRow + d][startCol + k - 1 - d];
        }
        if (diag2Sum != expectedSum) {
            return false;
        }
        
        return true;
    }
};