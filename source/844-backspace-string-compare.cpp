class Solution {
public:
    bool backspaceCompare(string s, string t) {
        int si=s.length()-1;
        int ti=t.length()-1;
        int sb=0, tb=0;

        char cs, ct; // current s, t char

        while (!((si<0) || (ti<0))) {
            cs = s[si];
            ct = t[ti];

            if (cs=='#') {
                si--;
                sb++;
            }
            else if (ct=='#') {
                ti--;
                tb++;
            }
            else if (sb!=0) {
                si--;
                sb--;
            }
            else if (tb!=0) {
                ti--;
                tb--;
            }
            else if (cs==ct) {
                si--;
                ti--;
            }
            else {
                return false;
            }
        }
        while (si>=0) { // if escaped before reducing si
            cs = s[si];
            if (cs=='#') {
                si--;
                sb++;
            }
            else if (sb!=0) {
                si--;
                sb--;
            }
            else {
                return false;
            }
        }
        while (ti>=0) { // if escaped before reducing ti
            ct = t[ti];
            if (ct=='#') {
                ti--;
                tb++;
            }
            else if (tb!=0) {
                ti--;
                tb--;
            }
            else {
                return false;
            }
        }

        return si==ti;
    }
};

