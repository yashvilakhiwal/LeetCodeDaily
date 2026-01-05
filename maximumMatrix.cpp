class Solution {
public:
    long long maxMatrixSum(vector<vector<int>>& matrix) {
        int n=matrix.size();
        long long totalSum=0;
        int minAbsValue=INT_MAX;
        int negativeCount=0;

        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                int val=matrix[i][j];
                totalSum+=abs(val);

                if(val<0){
                    negativeCount++;
                }
                minAbsValue=min(minAbsValue,abs(val));

                
            }
        }
        if(negativeCount%2==1){
                    totalSum-=2*minAbsValue;
                }
                return totalSum;

    }
};