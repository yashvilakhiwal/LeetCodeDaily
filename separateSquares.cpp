class Solution {
public:
    double separateSquares(vector<vector<int>>& squares) {
        double totalArea = 0;
        for (auto& sq : squares) {
            long long l = sq[2];
            totalArea += l * l;
        }
        
        double target = totalArea / 2.0;
        double minY = 1e9, maxY = 0;
        for (auto& sq : squares) {
            minY = min(minY, (double)sq[1]);
            maxY = max(maxY, (double)(sq[1] + sq[2]));
        }
        double left = minY, right = maxY;
        
        while (right - left > 1e-6) {
            double mid = (left + right) / 2.0;
            double areaBelow = calculateAreaBelow(squares, mid);
            
            if (areaBelow < target) {
                left = mid;
            } else {
                right = mid;
            }
        }
        
        return left;
    }
    
private:
    double calculateAreaBelow(vector<vector<int>>& squares, double y) {
        double area = 0;
        for (auto& sq : squares) {
            double bottom = sq[1];
            double top = sq[1] + sq[2];
            double side = sq[2];
            if (y <= bottom) {
                area += 0;
            } else if (y >= top) {
                area += side * side;
            } else {
                double heightBelow = y - bottom;
                area += heightBelow * side;
            }
        }
        return area;
    }
};