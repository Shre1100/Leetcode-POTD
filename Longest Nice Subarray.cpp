// You are given an array nums consisting of positive integers.
// We call a subarray of nums nice if the bitwise AND of every pair of elements that are in different positions in the subarray is equal to 0.
// Return the length of the longest nice subarray.
// A subarray is a contiguous part of an array.
// Note that subarrays of length 1 are always considered nice.
// Concept used --> Sliding Window, Bit Manipulation

class Solution {
public:
    int longestNiceSubarray(vector<int>& nums) {
        int l = 0;
        int ans = 1;
        int bits = 0;
        for(int r = 0; r<nums.size(); r++){
            while((bits & nums[r])!=0){
                bits ^= nums[l];
                l++;
            }
            bits |= nums[r];
            ans = max(ans,r-l+1);
        }
        return ans;
    }
};
