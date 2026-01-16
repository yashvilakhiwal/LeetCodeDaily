class Solution {
public:
    int maximizeSquareArea(int m, int n, vector<int>& hFences, vector<int>& vFences) {
        const int MOD = 1e9 + 7;
        
        vector<int> hPositions = {1, m};
        for (int fence : hFences) {
            hPositions.push_back(fence);
        }
        
        vector<int> vPositions = {1, n};
        for (int fence : vFences) {
            vPositions.push_back(fence);
        }
        
        sort(hPositions.begin(), hPositions.end());
        sort(vPositions.begin(), vPositions.end());
        
        unordered_set<int> hDistances;
        for (int i = 0; i < hPositions.size(); i++) {
            for (int j = i + 1; j < hPositions.size(); j++) {
                hDistances.insert(hPositions[j] - hPositions[i]);
            }
        }
        
        int maxSide = -1;
        for (int i = 0; i < vPositions.size(); i++) {
            for (int j = i + 1; j < vPositions.size(); j++) {
                int dist = vPositions[j] - vPositions[i];
                if (hDistances.count(dist)) {
                    maxSide = max(maxSide, dist);
                }
            }
        }
        
        if (maxSide == -1) {
            return -1;
        }

        long long area = (long long)maxSide * maxSide;
        return area % MOD;
    }
};