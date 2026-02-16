class Solution {
public:
    int reverseBits(int n) {
        int dummy=0;
        for(int i=0;i<32;+i++)
        {
            int lastbit=n&(1<<i);
            if(lastbit)
            dummy=dummy|(1<<(31-i));
        }
        return dummy;
    }
};