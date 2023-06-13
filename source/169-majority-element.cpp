// this code consists of Moore's voting algorithm.

class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int answer=nums[0];
        int count=0;
        for (int i=1; i<nums.size(); i++) {
            if (nums[i]==answer) {
                count++;
            }
            else {
                count--;
                if (count<0) {
                    answer=nums[i];
                    count=0;
                }
            }
        }
        return answer;
    }
};
