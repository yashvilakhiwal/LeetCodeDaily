class Solution {
public:
    int maximalRectangle(vector<vector<char>>& matrix) {
        if (matrix.empty() || matrix[0].empty()) return 0;
        
        int rows = matrix.size();
        int cols = matrix[0].size();
        vector<int> heights(cols, 0);
        int maxArea = 0;
        

        for (int i = 0; i < rows; i++) {

            for (int j = 0; j < cols; j++) {
                if (matrix[i][j] == '1') {
                    heights[j]++;
                } else {
                    heights[j] = 0;
                }
            }
            

            maxArea = max(maxArea, largestRectangleInHistogram(heights));
        }
        
        return maxArea;
    }
    
private:
    int largestRectangleInHistogram(vector<int>& heights) {
        stack<int> st;
        int maxArea = 0;
        int n = heights.size();
        
        for (int i = 0; i < n; i++) {

            while (!st.empty() && heights[i] < heights[st.top()]) {
                int h = heights[st.top()];
                st.pop();

                int w = st.empty() ? i : i - st.top() - 1;
                maxArea = max(maxArea, h * w);
            }
            st.push(i);
        }

        while (!st.empty()) {
            int h = heights[st.top()];
            st.pop();
            int w = st.empty() ? n : n - st.top() - 1;
            maxArea = max(maxArea, h * w);
        }
        
        return maxArea;
    }
};