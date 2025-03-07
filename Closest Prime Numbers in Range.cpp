//Problem Statement --> Given two positive integers left and right, find the two integers num1 and num2 such that: 1)left <= num1 < num2 <= right  2) Both num1 and num2 are prime numbers 
// 3) num2 - num1 is the minimum amongst all other pairs satisfying the above conditions.
//Return the positive integer array ans = [num1, num2]. If there are multiple pairs satisfying these conditions, return the one with the smallest num1 value. If no such numbers exist, return [-1, -1]

class Solution {
public:
    vector<int> closestPrimes(int left, int right) {
        auto is_prime = [](int n) {
            if (n <= 1) return false;
            if (n <= 3) return true;
            if (n % 2 == 0 || n % 3 == 0) return false;
            for (int i = 5; i * i <= n; i += 6) {
                if (n % i == 0 || n % (i + 2) == 0)
                    return false;
            }
            return true;
        };

        vector<int> primes;
        for (int num = max(2, left); num <= right; ++num) {
            if (is_prime(num)) {
                primes.push_back(num);
            }
        }

        if (primes.size() < 2) {
            return {-1, -1};
        }

        int min_gap = INT_MAX;
        vector<int> result = {-1, -1};

        for (int i = 1; i < primes.size(); ++i) {
            int gap = primes[i] - primes[i - 1];
            if (gap < min_gap) {
                min_gap = gap;
                result = {primes[i - 1], primes[i]};
            }
        }

        return result; 
    }
};
