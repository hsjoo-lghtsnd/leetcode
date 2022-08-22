class Solution {
public:
    bool isPowerOfFour(int n) {
        switch (n) {
            case 1:
            case 4:
            case 4<<2:
            case 4<<4:
            case 4<<6:
            case 4<<8:
            case 4<<10:
            case 4<<12:
            case 4<<14:
            case 4<<16:
            case 4<<18:
            case 4<<20:
            case 4<<22:
            case 4<<24:
            case 4<<26:
            case 4<<28:
                return true;
            default:
                return false;
        }
    }
};

