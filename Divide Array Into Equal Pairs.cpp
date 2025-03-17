// You are given an integer array nums consisting of 2 * n integers.
// You need to divide nums into n pairs such that:
// Each element belongs to exactly one pair.
// The elements present in a pair are equal.
// Return true if nums can be divided into n pairs, otherwise return false.

class Solution {
public:
    bool divideArray(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int n = nums.size()/2;
        int cnt=0;
        for (int i = 0; i < nums.size(); i += 2) {
            if (nums[i] != nums[i + 1] && cnt<n) {return false;}
            cnt++;
        }
        return true;
    }
};
