class Solution {
public:
    int minPairSum(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int n=nums.size();
        int max_sum=0;
        for(int i=0;i<n/2;i++){
            int current_sum=nums[i]+nums[n-1-i];
            if(current_sum>max_sum){
                max_sum=current_sum;
            }
        }
        return max_sum;
    }
};