// You are given an integer array nums of length n and a 2D array queries where queries[i] = [li, ri, vali].
// Each queries[i] represents the following action on nums:
// Decrement the value at each index in the range [li, ri] in nums by at most vali.
// The amount by which each value is decremented can be chosen independently for each index.
// A Zero Array is an array with all its elements equal to 0.
// Return the minimum possible non-negative value of k, such that after processing the first k queries in sequence, nums becomes a Zero Array. If no such k exists, return -1.
// Concept used --> Binary Search, Array.
class Solution {
public:
    int minZeroArray(vector<int>& nums, vector<vector<int>>& queries) {
        int n = nums.size();
        auto canMakeZeroArray = [&](int k) {
            vector<int> diff(n + 1, 0);
            for (int i = 0; i < k; i++) {
                int left = queries[i][0], right = queries[i][1], val = queries[i][2];
                diff[left] += val;
                diff[right + 1] -= val;
            }
            int currVal = 0;
            for (int i = 0; i < n; i++) {
                currVal += diff[i];
                if (currVal < nums[i]) return false;
            }
            return true;
        };
        if (all_of(nums.begin(), nums.end(), [](int x) { return x == 0; })) return 0;
        int left = 1, right = queries.size();
        if (!canMakeZeroArray(right)) return -1;
        while (left < right) {
            int mid = left + (right - left) / 2;
            if (canMakeZeroArray(mid)) right = mid;
            else left = mid + 1;
        }
        return left;
    }
};
