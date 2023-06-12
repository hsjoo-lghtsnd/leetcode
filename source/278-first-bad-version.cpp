// The API isBadVersion is defined for you.
// bool isBadVersion(int version);

// trinary search would be faster, but requires O(n) space for the check.
class Solution {
public:
    int firstBadVersion(int n) {
        int MAX = n;
        int MIN = 0;
        bool result_is_true;
        int now;
        int answer;

        while (MAX > MIN) {
            now = MIN + (MAX-MIN)/2;
            result_is_true = isBadVersion(now);
            if (result_is_true) {
                MAX = now;
            }
            else {
                MIN = now+1;
            }
        }

        return MIN;
    }
};

