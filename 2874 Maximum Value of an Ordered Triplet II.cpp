// You are given a 0-indexed integer array nums.
// Return the maximum value over all triplets of indices (i, j, k) such that i < j < k. If all such triplets have a negative value, return 0.
// The value of a triplet of indices (i, j, k) is equal to (nums[i] - nums[j]) * nums[k].

class Solution {
public:
    long long maximumTripletValue(vector<int>& nums) {
        int maxi = INT_MIN, diff = 0, n = nums.size();
        long long res = 0;
        
        for (int i = 0; i < n; i++) {
            maxi = max(maxi, nums[i]); // Update the max value seen so far
            if (i >= 2)
                res = max(res, (long long)diff * nums[i]); // Compute max triplet value
            if (i >= 1)
                diff = max(diff, maxi - nums[i]); // Update max difference
        }
        
        return res;
    }
};
