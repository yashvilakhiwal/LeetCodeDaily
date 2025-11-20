class Solution {
public:
    int intersectionSizeTwo(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end(), [](const vector<int>& a, const vector<int>& b) {
            if (a[1] != b[1]) return a[1] < b[1];
            return a[0] > b[0];
        });
        
        int n = intervals.size();
        vector<int> result;
        
        for (int i = 0; i < n; i++) {
            int start = intervals[i][0];
            int end = intervals[i][1];
            int count = 0;
            int m = result.size();
            if (m >= 1 && result[m-1] >= start && result[m-1] <= end) {
                count++;
            }
            if (m >= 2 && result[m-2] >= start && result[m-2] <= end) {
                count++;
            }
            if (count == 0) {
                result.push_back(end - 1);
                result.push_back(end);
            } else if (count == 1) {
                result.push_back(end);
            }
        }
        
        return result.size();
    }
};