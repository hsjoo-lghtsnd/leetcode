class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        int N = strs.size();
        string target=strs[0];
        string temp;
        if (N==1) {
            return target;
        }
        string res = "";
        for (int i=0; i<200; i++) {
            for (int j=1; j<N; j++) {
                temp = strs[j];
                if (temp.length() == i) {
                    return res;
                }
                if (temp[i] != target[i]) {
                    return res;
                }
            }
            res = res + target[i];
        }
        return res;
    }
};
