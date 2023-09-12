class Solution {
public:
    vector<int> countBits(int n) {
        vector<int> res;
        int cur;
        int temp;

        res.push_back(0);

        for (int i=1; i<n+1; i++) {
            cur=i;
            temp=1;
            while (cur>1) {
                temp += ((cur/2)*2==cur) ? 0 : 1;
                cur/=2;
            }
            res.push_back(temp);
        }

        return res;
    }
};

