class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        int N = ransomNote.length();
        int M = magazine.length();
        
        int ran[26] = {0};
        int mag[26] = {0};
        
        for (int i=0; i<N; i++) {
            ran[ransomNote[i]-'a'] += 1;
        }
        for (int i=0; i<M; i++) {
            mag[magazine[i] - 'a'] += 1;
        }
        
        for (int i=0; i<26; i++) {
            if (mag[i] < ran[i]) {
                return false;
            }
        }
        return true;
    }
};
