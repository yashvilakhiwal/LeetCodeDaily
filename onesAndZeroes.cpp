class Solution {
public:
    int findMaxForm(vector<string>& strs, int m, int n) {
        unordered_map<int, int> memo;
        return backtrack(strs, 0, m, n, memo);
    }
    
private:

    int encodeKey(int idx, int m, int n) {

        return idx * 10000 + m * 100 + n;
    }
    
    int backtrack(vector<string>& strs, int idx, int m, int n, 
                  unordered_map<int, int>& memo) {
        if (idx == strs.size()) {
            return 0;
        }
        
        int key = encodeKey(idx, m, n);
        if (memo.find(key) != memo.end()) {
            return memo[key];
        }
        
       
        int zeros = 0, ones = 0;
        for (char c : strs[idx]) {
            if (c == '0') zeros++;
            else ones++;
        }
        
        int skip = backtrack(strs, idx + 1, m, n, memo);

        int include = 0;
        if (zeros <= m && ones <= n) {
            include = 1 + backtrack(strs, idx + 1, m - zeros, n - ones, memo);
        }
        
        memo[key] = max(skip, include);
        return memo[key];
    }
};