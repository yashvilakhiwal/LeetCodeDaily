class Solution {
public:
    int MOD = 1e9 + 7;
    map<pair<int,int>, int> memo;
    int solve(int row, int n, int prev) {
        if (row == n) return 1;  
        if (memo.count({row, prev})) return memo[{row, prev}];
        long long ways = 0;
         for (int a = 0; a < 3; a++) {
            for (int b = 0; b < 3; b++) {
                for (int c = 0; c < 3; c++) {
                    if (a == b || b == c) continue;
                    int curr = a*9 + b*3 + c;  
                    if (prev == -1 || 
                        (prev/9 != a && (prev/3)%3 != b && prev%3 != c)) {
                        ways += solve(row + 1, n, curr);
                    }
                }
            }
        }
        return memo[{row, prev}] = ways % MOD;
    }
    int numOfWays(int n) {
        return solve(0, n, -1);
    }
};