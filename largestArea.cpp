class Solution {
public:
    long long largestSquareArea(vector<vector<int>>& bottomLeft, vector<vector<int>>& topRight) {
        int n = bottomLeft.size();
        long long maxArea = 0;
        
        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                int a1 = bottomLeft[i][0], b1 = bottomLeft[i][1];
                int c1 = topRight[i][0], d1 = topRight[i][1];
                
                int a2 = bottomLeft[j][0], b2 = bottomLeft[j][1];
                int c2 = topRight[j][0], d2 = topRight[j][1];
                
                int intersectLeft = max(a1, a2);
                int intersectBottom = max(b1, b2);
                int intersectRight = min(c1, c2);
                int intersectTop = min(d1, d2);
                
                if (intersectLeft < intersectRight && intersectBottom < intersectTop) {
                    int width = intersectRight - intersectLeft;
                    int height = intersectTop - intersectBottom;
                    int sideLength = min(width, height);
                    long long area = (long long)sideLength * sideLength;
                    
                    maxArea = max(maxArea, area);
                }
            }
        }
        
        return maxArea;
    }
};