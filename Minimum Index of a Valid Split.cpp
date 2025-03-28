// An element x of an integer array arr of length m is dominant if more than half the elements of arr have a value of x.
// You are given a 0-indexed integer array nums of length n with one dominant element.
// You can split nums at an index i into two arrays nums[0, ..., i] and nums[i + 1, ..., n - 1], but the split is only valid if:
// 0 <= i < n - 1
// nums[0, ..., i], and nums[i + 1, ..., n - 1] have the same dominant element.
// Here, nums[i, ..., j] denotes the subarray of nums starting at index i and ending at index j, both ends being inclusive. Particularly, if j < i then nums[i, ..., j] denotes an empty subarray.
// Return the minimum index of a valid split. If no valid split exists, return -1.

class Solution {
public:
    int minimumIndex(vector<int>& nums) {
        const int n=nums.size();
        int cnt=0, xM=0, maxF=0;
        //Las Vegas
        srand(time(NULL));
        int sz=n;
        vector<int> idx(n);
        iota(idx.begin(), idx.end(), 0);
        while(sz){
            const int i=rand()%sz;
            xM=nums[idx[i]];
            maxF=count(nums.begin(), nums.end(), xM);
            if (maxF*2>n) break;  
            swap(idx[i], idx[--sz]); 
        }
    //    cout<<xM<<" maxF="<<maxF<<endl;
        int cntxM=0;
        for(int i=0; i<n; i++){
            cntxM+=nums[i]==xM;
            if (cntxM*2>(i+1) && ((maxF-cntxM)*2>(n-i-1)))
                return i;
        }
        return -1;
    }
};
