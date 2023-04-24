class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        int a, b;
        while (stones.size()>1) {
            sort(stones.begin(),stones.end());
            a = stones.back();
            stones.pop_back();
            b = stones.back();
            stones.pop_back();
            a = a-b;
            if (a == 0) {
                continue;
            }
            else {
                stones.push_back(a);
            }
        }
        if (!stones.empty()) {
            return stones.back();
        }
        return 0;
    }
};
