class Solution {
public:
    bool isAnagram(string s, string t) {
        if (s.length() != t.length())
            return false;
        
        int cs[26]={0};
        int ts[26]={0};
        int L = s.length();
        
        for (int i=0; i<L; i++) {
            cs[s[i]-'a'] += 1;
            ts[t[i]-'a'] += 1;
        }
        
        for (int i=0; i<26; i++) {
            if (cs[i] != ts[i])
                return false;
        }
        
        return true;
    }
};
