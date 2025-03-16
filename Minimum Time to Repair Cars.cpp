// You are given an integer array ranks representing the ranks of some mechanics. ranksi is the rank of the ith mechanic. A mechanic with a rank r can repair n cars in r * n2 minutes.
// You are also given an integer cars representing the total number of cars waiting in the garage to be repaired.
// Return the minimum time taken to repair all the cars.
// Note: All the mechanics can repair the cars simultaneously.

//Concept used --> Binary Search

class Solution {
private:
    bool timeIsSuff(vector<int>& ranks, int cars, long long minGiven) {
        long long carsDone = 0;
        for (int r : ranks) {
            long long c2 = minGiven / r;
            long long c = floor(sqrt(c2));
            carsDone += c;
        }
        return carsDone >= cars;
    }
public:
    long long repairCars(vector<int>& ranks, int cars) {
        long long left = 1, right = 1e14;
        while (left < right) {
            long long mid = (left + right) / 2;
            if (timeIsSuff(ranks, cars, mid)) {
                right = mid;
            } else {
                left = mid + 1;
            }
        }
        return left;
    }
};
