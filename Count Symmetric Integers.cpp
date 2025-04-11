// You are given two positive integers low and high.
// An integer x consisting of 2 * n digits is symmetric if the sum of the first n digits of x is equal to the sum of the last n digits of x. Numbers with an odd number of digits are never symmetric.
// Return the number of symmetric integers in the range [low, high].

class Solution {
public:
    int countSymmetricIntegers(int low, int high) {
        int count = 0;
        for (int num = low; num <= high; ++num) {
            string s = to_string(num);
            if (s.size() % 2 == 0) {
                int mid = s.size() / 2;
                int leftSum = 0, rightSum = 0;
                for (int i = 0; i < mid; ++i) leftSum += s[i] - '0';
                for (int i = mid; i < s.size(); ++i) rightSum += s[i] - '0';
                if (leftSum == rightSum) count++;
            }
        }
        return count;
    }
};
