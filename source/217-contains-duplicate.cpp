class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        map<int,int> dict;
        for (int i=0; i<nums.size(); i++) {
            if (!dict[nums[i]]) dict[nums[i]]++;
            else return true;
        }
        return false;
    }
};

