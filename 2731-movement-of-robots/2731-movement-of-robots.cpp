class Solution {
public:
    int sumDistance(vector<int>& nums, string s, int d) {
        int n = nums.size(), M = 1e9+7;
        vector<long long> finalNums(n, 0);
        // final array is same with or without collisons
        for(int i = 0; i < n; i++){
            if(s[i] == 'R'){
                finalNums[i] = (long long)nums[i] + d;
            }
            else{
                finalNums[i] = (long long)nums[i] - d;
            }
        }
        long long ans = 0;
        /*
        1. Sort the Array:
        Because |A[i] - A[j]| = |A[j] - A[i]|, changing the order of elements does not change the final sum. Sorting ensures that for any index i, every element before it (j < i) is less than or equal to A[i], eliminating the need for absolute value checks.
        2. Calculate Each Element's Contributio:
        At index i, there are i elements to its left (A[0], A[1],...., A[i-1]). The sum of differences between A[i] and all preceding elements is:
        |A[i]-A[0]|+|A[i]-A[1]|+ .... +|A[i]-A[i-1])|, Grouping the terms together simplifies this to:
        (i times A[i])-(A[0]+A[1]+ ... +A[i-1])The second part is simply the prefix sum of elements before index \(i\).
        */
        sort(finalNums.begin(), finalNums.end());
        long long prefixSum = 0;
        for(int i = 0; i < n; i++){
            ans += ((long long)i*finalNums[i] - prefixSum) % M;
            prefixSum += finalNums[i];
        }
        return ans % M;
    }
};