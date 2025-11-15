class Solution {
public:
    int numberOfSubstrings(string s) {
        int n = s.length();
        long long count = 0;

        vector<int> zeros;
        for (int i = 0; i < n; i++) {
            if (s[i] == '0') {
                zeros.push_back(i);
            }
        }
        
        int totalZeros = zeros.size();
        int limit = min(200, totalZeros);
        

        for (int i = 0; i < n; i++) {

            int zeroIdx = lower_bound(zeros.begin(), zeros.end(), i) - zeros.begin();
            int nextZero = (zeroIdx < totalZeros) ? zeros[zeroIdx] : n;
            count += nextZero - i;
            for (int k = 1; k <= limit && zeroIdx + k - 1 < totalZeros; k++) {
                int requiredOnes = k * k;
                int kthZeroPos = zeros[zeroIdx + k - 1];
                int rightBound = (zeroIdx + k < totalZeros) ? zeros[zeroIdx + k] - 1 : n - 1;

                int currentOnes = (kthZeroPos - i + 1) - k;
                
                if (currentOnes >= requiredOnes) {

                    count += rightBound - kthZeroPos + 1;
                } else {
                    int deficit = requiredOnes - currentOnes;
                    int minEnd = kthZeroPos + deficit;
                    
                    if (minEnd <= rightBound) {
                        count += rightBound - minEnd + 1;
                    }
                }
            }
        }
        
        return count;
    }
};