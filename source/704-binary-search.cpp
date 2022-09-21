/* I was good at binary search, but I'm not currently.*/

class Solution {
private:
    int updateStep(int step) {
        if (step>1) {
            return step/2;
        }
        return 1;
    }
public:
    int search(vector<int>& nums, int target) {
        int L = nums.size();
        int cur = L/2;
        int step = updateStep(cur);
        int temp = L*L;
        
        for (int i=0; temp>0; temp/=2) {
            if (nums[cur] == target) {
                return cur;
            }
            else if (nums[cur] > target) {
                cur -= step;
            }
            else if (nums[cur] < target) {
                cur += step;
            }
            step = updateStep(step);
            if ((cur < 0) || (cur >= L)) {
                return -1;
            }
        }
        
        return -1;
    }
};
