class Solution {
public:
    int maximizeSquareHoleArea(int n, int m, vector<int>& hBars, vector<int>& vBars) {
        int maxH=getLongestSequence(hBars);
        int maxV=getLongestSequence(vBars);
        int side=min(maxH,maxV);
        return side*side;
    }
private:
    int getLongestSequence(vector<int>&bars){
        if((bars.empty())) return 1;
        sort(bars.begin(),bars.end());
        int maxLen=1,currLen=1;
        for(size_t i=0;i<bars.size()-1;i++){
            if(bars[i+1]-bars[i]==1){
                currLen++;
            }
            else{
                maxLen=max(currLen,maxLen);
                currLen=1;
            }
        }
        maxLen=max(maxLen,currLen);
        return maxLen+1;
    }
};