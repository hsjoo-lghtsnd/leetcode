class Solution {
public:
    int firstUniqChar(string s) {
        // set initial data structure: unique={-1,-1,...,-1}
        int unique[26]={0};
        for (int i=0; i<26; i++) {
            unique[i] -= 1;
        }
        
        // parse
        int N = s.length();
        int c;
        for (int i=0; i<N; i++) {
            c = s[i]-'a';
            
            if (unique[c] == -1) {
                unique[c] = i;
            }
            else if (unique[c] != -2) {
                unique[c] = -2;
            }
        }
        
        // post-processing
        int my_min = N;
        for (int i=0; i<26; i++) {
            if ((unique[i] > -1) && (unique[i] < my_min)) {
                my_min = unique[i];
            }
        }
        if (my_min == N) {
            my_min = -1;
        }
        return my_min;
    }
};
