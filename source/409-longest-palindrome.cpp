class Solution {
public:
    int longestPalindrome(string s) {
        vector<int> counts(26*2, 0);
        const int N = s.length();
        char c;
        int result = 0;

        for (int i=0; i<N; i++) {
            c = s[i];
            if (c>='a') {
                counts[c-'a'] += 1;
            }
            else {
                counts[c-'A'+26] += 1;
            }
        }

        c = 0;
        for (int i=0; i<52; i++) {
            result += (counts[i]/2)*2;
            c = c | counts[i]%2;
        }

        return result+c;
    }
};

