class Solution {
public:
    int binaryGap(int n) {
        int maxDist = 0, prev = -1, pos = 0;
        while (n) {
            if (n & 1) {
                if (prev != -1) maxDist = max(maxDist, pos - prev);
                prev = pos;
            }
            pos++;
            n >>= 1;
        }
        return maxDist;
    }
};