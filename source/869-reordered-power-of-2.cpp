#include <cmath>

class Solution {
private:
    bool reordertwo(int target, int given) {
        int N = int(floor(log10(given)))+1;
        int t[10] = {0};
        int g[10] = {0};
        int p_t, p_g;
        
        for (int i=0; i<N; i++) {
            p_t = target%10;
            p_g = given%10;
            
            t[p_t] += 1;
            g[p_g] += 1;
            
            target /= 10;
            given /= 10;
        }
        
        for (int i=0; i<10; i++) {
            if (t[i] != g[i]) {
                return false;
            }
        }
        return true;
    }
public:
    bool reorderedPowerOf2(int n) {
        // 1 <= n <= 1e9
        // thus, 0 <= log2(n) < 30
        // log10(n) < 1: n=1,2,4,8 (4)
        // log10(n) < 2: n=16,32,64 (3)
        // log10(n) < 3: n=128,256,512 (3)
        // log10(n) < 4: n=1024, 2048, 4096, 8192 (4)
        // ...
        // 4, 3, 3, 4, 3, 3, 4, 3, 3
        string passcode = "433433433";
        
        int _FLOOR = int(floor(log10(n)));
        int _MAX = passcode[_FLOOR]-'0';
        int now2 = int(pow(2,floor(_FLOOR/log10(2))+1));
        
        if (!_FLOOR) {
            switch(n) {
                case 1:
                case 2:
                case 4:
                case 8:
                    return true;
                default:
                    return false;
            }
        }
        
        for (int i=0; i<_MAX; i++) {
            if (reordertwo(now2,n)) {
                return true;
            }
            else {
                now2 *= 2;
            }
        }
        
        return false;
    }
};

