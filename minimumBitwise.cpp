class Solution {
public:
    vector<int> minBitwiseArray(vector<int>& nums) {
        vector<int> ans;
        for (int n : nums) {
            if (n % 2 == 0) {
                ans.push_back(-1);
                continue;
            }
            int result = n;
            for (int i = 0; i < 31; i++) {
                if ((n & (1 << i)) && !(n & (1 << (i + 1)))) {
                    result = n ^ (1 << i); 
                    break;
                }
            }
            ans.push_back(result);
        }
        return ans;
    }
};