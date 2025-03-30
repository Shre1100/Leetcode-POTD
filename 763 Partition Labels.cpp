// You are given a string s. We want to partition the string into as many parts as possible so that each letter appears in at most one part. For example, the string "ababcc" can be partitioned into ["abab", "cc"], but partitions such as ["aba", "bcc"] or ["ab", "ab", "cc"] are invalid.
// Note that the partition is done so that after concatenating all the parts in order, the resultant string should be s.
// Return a list of integers representing the size of these parts.

class Solution {
public:
    vector<int> partitionLabels(string s) {
       const int n=s.size();
        array<pair<int, int>, 26> P;// (start, end)
        P.fill({n, -1});
        for(int i=0; i<n; i++){
            int x=s[i]-'a';
            P[x].first=min(i, P[x].first);
            P[x].second=i;
        } 

        vector<int> pLen;
        int start = 0, end = -1;
        for (int i = 0; i < n; i++) {
            int x = s[i] - 'a';
            end = max(end, P[x].second);
            if (i == end) {
                pLen.push_back(end - start + 1);
                start = i + 1;
            }
        }
        return pLen; 
    }
};
