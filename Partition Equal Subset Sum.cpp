// Given an integer array nums, return true if you can partition the array into two subsets such that the sum of the elements in both subsets is equal or false otherwise.

class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int sum = 0, n = nums.size();
        for (int i = 0; i < n; i++) {
            sum += nums[i];
        }
        if (sum % 2 != 0)
            return false;

        bitset<10001> bit(1);
        for (auto i : nums) {
            bit |= bit << i;
            if (bit[sum / 2])
                return true;
        }
        return bit[sum / 2];
    }
};
