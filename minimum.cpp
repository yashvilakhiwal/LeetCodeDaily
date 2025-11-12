class Solution {
public:
    int minOperations(vector<int>& nums) {
        int n = nums.size();
        int ones = 0;
        for (int num : nums) {
            if (num == 1) ones++;
        }
        if (ones > 0) {
            return n - ones;
        }
        int overall_gcd = nums[0];
        for (int i = 1; i < n; i++) {
            overall_gcd = __gcd(overall_gcd, nums[i]);
        }
        
        if (overall_gcd > 1) {
            return -1;
        }
        int min_ops = INT_MAX;
        for (int i = 0; i < n; i++) {
            int current_gcd = nums[i];
            for (int j = i; j < n; j++) {
                current_gcd = __gcd(current_gcd, nums[j]);
                
                if (current_gcd == 1) {
                    min_ops = min(min_ops, (j - i) + (n - 1));
                    break;
                }
            }
        }
        
        return min_ops == INT_MAX ? -1 : min_ops;
    }
};