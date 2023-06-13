class Solution {
public:
    int climbStairs(int n) {
        vector<unsigned int> answers;
        int count = 2;

        answers.push_back(1);
        if (n==1) return 1;
        answers.push_back(2);
        if (n==2) return 2;

        while (count<=n) {
            answers.push_back(answers[count-2]+answers[count-1]);
            count++;
        }
        return answers[n-1];
    }
};
