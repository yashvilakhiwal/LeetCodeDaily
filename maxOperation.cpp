class Solution {
public:
    int maxOperations(string s) {
        int operations = 0;
        int onesCount = 0;
        
        for (int i = 0; i < s.length(); i++) {
            if (s[i] == '1') {
                onesCount++;
                if (i + 1 < s.length() && s[i + 1] == '0') {
                    operations += onesCount;
                }
            }
        }
        
        return operations;
    }
};