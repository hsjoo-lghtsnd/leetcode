class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        int N = nums.size();
        vector<int> v(2);
        for (int i=0; i<N; i++) {
            for (int j=i+1; j<N; j++) {
                if (nums[i]+nums[j] == target) {
                    v[0] = i;
                    v[1] = j;
                    return v;
                }
            }
        }
        return v;
    }
};
