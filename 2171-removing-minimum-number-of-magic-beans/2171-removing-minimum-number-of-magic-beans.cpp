class Solution {
public:
    long long minimumRemoval(vector<int>& beans) {
        int n = beans.size();
        sort(beans.begin(), beans.end());
        vector<long long> prefixSum(n, 0);
        prefixSum[0] = beans[0];
        for(int i = 1; i < n; i++){
            prefixSum[i] = beans[i]+prefixSum[i-1];
        }
        // select one element, turn it's left eles into 0s and right eles into selected one
        long long ans;
        ans = prefixSum[n-1]-prefixSum[0] - (long long)(n-1)*beans[0]; // first element selected
        for(int i = 1; i < n; i++){
            long long currAns = prefixSum[i-1] + (prefixSum[n-1]-prefixSum[i]-(long long)(n-i-1)*beans[i]);
            ans = min(ans, currAns);
        }
        return ans;
    }
};