// Greedy approach:
class Solution {
public:
    int minimizeArrayValue(vector<int>& nums) {
        int n = nums.size();
        long long prefixSum = nums[0];
        long long maxi = nums[0];
        for(int i = 1; i < n; i++){
            prefixSum += nums[i];
            long long currLeastMax = (prefixSum + i) / (i + 1); // least possible maximum in sbarray: 0 to i
            maxi = max(maxi, currLeastMax); // greedyly take the maximum between previous groups and current groups
        }
        return maxi;
    }
};
// (prefixSum + i) / (i + 1) == ceil(prefixSum/(i+1))