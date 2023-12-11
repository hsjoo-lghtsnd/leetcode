class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int N = nums.size();
        int res = 0;
        for (int i=0; i<N; i++) {
            res ^= nums[i];
        }
        return res;
    }
};

