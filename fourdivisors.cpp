class Solution {
public:
    int sumFourDivisors(vector<int>& nums) {
        int n=nums.size();
        int sum=0;
        for(int i=0;i<n;i++){
            int count=0;
            int tempsum=0;
            for(int j=1;j*j<=nums[i];j++){
                if(nums[i]%j==0){
                    count++;
                    tempsum+=j;
                    if(j*j != nums[i]){
                        count++;
                        tempsum+=nums[i]/j;
                    }
                    if(count>4) break;
                }
            }
            if(count==4){
                sum+=tempsum;
            }
        }
        return sum;
    }
};