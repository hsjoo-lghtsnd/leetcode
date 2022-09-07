class Solution {
private:
    int maxbit(int divisor) {
        // CONTRACT: divisor > 0
        int ret;
        int temp = 1;
        for (int i=0; i<sizeof(int)*8; i++) {
            temp = 1<<i;
            if ((temp&divisor) != 0) {
                ret = i;
            }
        }
        return ret;
    }
    bool diffsign(int a, int b, int msb) {
        return ((a&msb)^(b&msb)) == msb;
    }
public:
    int divide(int dividend, int divisor) {
        const int msb=1<<(sizeof(int)*8-1);
        const int maxint = (~0)^msb;
        int ret=0;
        int temp=dividend&msb;
        int d=dividend;
        int tempd=d;
        
        if (divisor==1) {
            return dividend;
        }
        if (divisor == msb) {
            if (dividend == msb)
                return 1;
            return 0;
        }
        if (divisor<0) {
            if ((dividend == msb) && (divisor == -1)) {
                return maxint;
            }
            return -divide(dividend, -divisor);
        }
        
        // divisor > 0 below.
        if (diffsign(dividend,divisor,msb)) {
            // +=
            for (int i=(sizeof(int)*8-maxbit(divisor)-2); i>=0; i--) {
                tempd=(unsigned int)tempd + (unsigned int)(divisor<<i);
                if ((tempd!=0) && diffsign(tempd, d, msb)) {
                    tempd=d;
                }
                else {
                    d=tempd;
                    ret-=(1<<i);
                }
            }
            if (d!=0) {
                tempd+=divisor;
                if ((tempd!=0) && diffsign(tempd, d, msb)) {
                    tempd=d;
                }
                else {
                    d=tempd;
                    ret--;
                }
            }
        }
        else {
            // -=
            for (int i=(sizeof(int)*8-maxbit(divisor)-2); i>=0; i--) {
                tempd=(unsigned int)tempd - (unsigned int)(divisor<<i);
                if ((tempd!=0) && diffsign(tempd, d, msb)) {
                    tempd=d;
                }
                else {
                    d=tempd;
                    ret+=(1<<i);
                }
            }
            if (d!=0) {
                tempd-=divisor;
                if ((tempd!=0) && diffsign(tempd, d, msb)) {
                    tempd=d;
                }
                else {
                    d=tempd;
                    ret++;
                }
            }
        }
        
        
        
        
        return ret;
        
        /*
        if (divisor == 1<<31) {
            return 0;
        }
        if (dividend == 1<<31) {
            if (divisor < 0) {
                int temp = divide(dividend-divisor, divisor);
                if (temp == (1<<31)-1) {
                    return temp;
                }
                else {
                    return 1 + temp;
                }
            }
            else {
                int temp = -divide(-(dividend+divisor), divisor);
                if (temp == (1<<31)-1) {
                    return temp;
                }
                else {
                    return 1 + temp;
                }
            }
        }
        if (dividend < 0) {
            return -divide(-dividend, divisor);
        }
        if (divisor < 0) {
            return -divide(dividend, -divisor);
        }
        
        int ret = 0;
        while (dividend >= divisor) {
            if (ret == (1<<31)-1) {
                return temp;
            }
            else {
                return 1 + temp;
            }
        }
        else {
            return 0;
        }
        */
    }
};
