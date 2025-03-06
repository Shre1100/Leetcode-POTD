//Given a n x n grid and it contains numbers from the range [1,n*n]. Each number in the grid appears once but one number appears twice. Find the number which appears twice along with the missing number in the grid.
//used the concept of counting the occurences and then finding the output.
class Solution {
public:
    vector<int> findMissingAndRepeatedValues(vector<vector<int>>& grid) {
      int n = grid.size();
    unordered_map<int, int> num_count;
    int twice = 0;
    int missing = 0;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            num_count[grid[i][j]]++;
        }
    }
    for (int i = 1; i <= n * n; ++i) {
        if (num_count[i] == 2) {
            twice = i;
        } else if (num_count[i] == 0) {
            missing = i;
        }
    }

    return {twice, missing};
    }
};
