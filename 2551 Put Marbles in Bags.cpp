// You have k bags. You are given a 0-indexed integer array weights where weights[i] is the weight of the ith marble. You are also given the integer k.
// Divide the marbles into the k bags according to the following rules:
// No bag is empty.
// If the ith marble and jth marble are in a bag, then all marbles with an index between the ith and jth indices should also be in that same bag.
// If a bag consists of all the marbles with an index from i to j inclusively, then the cost of the bag is weights[i] + weights[j].
// The score after distributing the marbles is the sum of the costs of all the k bags.
// Return the difference between the maximum and minimum scores among marble distributions.

class Solution {
public:
    long long putMarbles(vector<int>& weights, int k) {
        if (k == 1) {
            return 0;
        }

        vector<int> pair_sums;
        for (size_t i = 0; i < weights.size() - 1; ++i) {
            pair_sums.push_back(weights[i] + weights[i + 1]);
        }

        sort(pair_sums.begin(), pair_sums.end());

        long long min_score = accumulate(pair_sums.begin(), pair_sums.begin() + (k - 1), 0LL);
        long long max_score = accumulate(pair_sums.end() - (k - 1), pair_sums.end(), 0LL);

        return max_score - min_score;
    }
};
