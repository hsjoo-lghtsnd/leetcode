class Solution {
public:
    int hammingWeight(uint32_t n) {
        uint32_t m=n;
        m = m&0x55555555;
        n = n&0xAAAAAAAA;
        n = m+(n>>1);

        m=n;
        m = m&0x33333333;
        n = n&0xCCCCCCCC;
        n = m+(n>>2);

        m=n;
        m = m&0x0F0F0F0F;
        n = n&0xF0F0F0F0;
        n = m+(n>>4);

        m=n;
        m = m&0x00FF00FF;
        n = n&0xFF00FF00;
        n = m+(n>>8);

        m=n;
        m = m&0x0000FFFF;
        n = n&0xFFFF0000;
        n = m+(n>>16);
        
        return n;
    }
};
