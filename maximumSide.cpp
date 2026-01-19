class Solution {
public:
    int maxSideLength(vector<vector<int>>& mat, int threshold) {
        int m = mat.size();
        int n = mat[0].size();
        
        vector<vector<int>> prefix(m + 1, vector<int>(n + 1, 0));
        
        for (int i = 1; i <= m; i++) {
            for (int j = 1; j <= n; j++) {
                prefix[i][j] = mat[i-1][j-1] + prefix[i-1][j] + prefix[i][j-1] - prefix[i-1][j-1];
            }
        }
        
        int maxLen = 0;
        
        for (int i = 1; i <= m; i++) {
            for (int j = 1; j <= n; j++) {
                int maxPossible = min(m - i + 1, n - j + 1);
                for (int len = 1; len <= maxPossible; len++) {
                    int i2 = i + len - 1;
                    int j2 = j + len - 1;
                    int sum = prefix[i2][j2] - prefix[i-1][j2] - prefix[i2][j-1] + prefix[i-1][j-1];
                    if (sum <= threshold) {
                        maxLen = max(maxLen, len);
                    }
                }
            }
        }
        
        return maxLen;
    }
};