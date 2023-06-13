class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int N = nums.size();
        int answer = nums[0];
        int temp_sum = nums[0];
        for (int i=1; i<N; i++) {
            temp_sum = temp_sum>0?temp_sum+nums[i]:nums[i];
            answer = temp_sum>answer?temp_sum:answer;
        }

        // logic for integral array: O(n^2)
        /*
        for (int i=0; i<N; i++) {
            for (int j=i+1; j<N; j++) {
                if (nums[j]-nums[i]>answer) {
                    answer = nums[j]-nums[i];
                }
            }
        }
        */
        return answer;
    }
};
