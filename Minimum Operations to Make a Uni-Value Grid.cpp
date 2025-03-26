// You are given a 2D integer grid of size m x n and an integer x. In one operation, you can add x to or subtract x from any element in the grid.
// A uni-value grid is a grid where all the elements of it are equal.
// Return the minimum number of operations to make the grid uni-value. If it is not possible, return -1.

class Solution {
public:
    int minOperations(vector<vector<int>>& grid, int x) {
       vector<int> values;
        for (const auto& row : grid) {
            for (int val : row) {
                values.push_back(val);
            }
        }

        sort(values.begin(), values.end());

        for (int val : values) {
            if (abs(val - values[0]) % x != 0) {
                return -1;
            }
        }

        int median = values[values.size() / 2];
        int operations = 0;

        for (int val : values) {
            operations += abs(val - median) / x;
        }

        return operations; 
    }
};
