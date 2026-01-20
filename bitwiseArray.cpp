class Solution {
public:
    vector<int> minBitwiseArray(vector<int>& nums) {
        vector<int> ans;
        
        for (int num : nums) {
            if (num % 2 == 0) {
                ans.push_back(-1);
                continue;
            }
            
            int result = -1;
            int pos = 0;
            int temp = num;
            
            while (temp & 1) {
                temp >>= 1;
                pos++;
            }
            
            if (pos > 0) {
                result = num ^ (1 << (pos - 1));
            } else {
                result = 0;
            }
            
            if (result != -1 && (result | (result + 1)) != num) {
                result = -1;
            }
            
            ans.push_back(result);
        }
        
        return ans;
    }
};