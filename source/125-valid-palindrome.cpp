class Solution {
private:
    char validChar(char c) {
        if ((c >= 'a') && (c <= 'z')) {
            return c;
        }
        if ((c >= 'A') && (c <= 'Z')) {
            return c-'A'+'a';
        }
        if ((c >= '0') && (c <= '9')) {
            return c;
        }
        return 0;
    }
public:
    bool isPalindrome(string s) {
        vector<char> v;
        char c;
        for (int i=0; i<s.size(); i++) {
            c = validChar(s[i]);
            if (c != 0) {
                v.push_back(c);
            }
        }
        
        
        int N = v.size();
        int maxlen = (N/2)+(N%2);
        
        for (int i=0; i<maxlen; i++) {
            if (v[i] != v[N-1-i])
                return false;
        }
        return true;
    }
};
