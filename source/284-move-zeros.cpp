class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int i=0, j=0;
        int N = nums.size();
        while (j < N) {
            while ((j<N) && nums[j++]==0);
            nums[i++]=nums[j-1];
        }
        while (i < N) {
            nums[i++] = 0;
        }
        return;
    }
};

