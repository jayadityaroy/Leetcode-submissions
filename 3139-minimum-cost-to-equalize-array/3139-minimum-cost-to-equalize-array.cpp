// Optimised approach:
class Solution {
public:
    int minCostToEqualizeArray(vector<int>& nums, int cost1, int cost2) {
        int n = nums.size();
        long long actualSum = 0;
        int mx = -1e9, mn = 1e9;
        long long cost = LLONG_MAX;
        int M = 1e9+7;
        for(int i = 0; i < n; i++){
            actualSum += nums[i];
            mx = max(mx, nums[i]);
            mn = min(mn, nums[i]);
        }
        if(2*cost1 <= cost2){ // eqalizing the array to mx individually is cheaper
            long long idealSum = 1LL*mx*n; // all element will be eqalized to mx
            long long reqSteps = idealSum - actualSum;
            cost = (reqSteps*cost1);
        }
        else{ // pairing is cheaper, so greedy use cost2 as much as possible
            for(int target = mx; target <= 2*mx; target++){
                long long idealSum = 1LL*target*n;
                long long reqSteps = idealSum - actualSum;
                long long maxStep = target - mn; //the biggest single need, which belongs to the smallest element
                long long otherSteps = reqSteps - maxStep; // steps needed by other eles
                long long pairs, singles;
                if(maxStep <= otherSteps){ // can form pair with nothing left out
                    pairs = reqSteps/2;
                    singles = reqSteps%2;
                }
                else{ // some steps will be covered using cost1 (left out with no pair)
                    pairs = reqSteps - maxStep; // since maxStep is so much greater than rest of the steps, pairing depends on the rest
                    singles = maxStep - pairs;
                }
                long long localCost = 1LL*pairs*cost2 + 1LL*singles*cost1;
                cost = min(cost, localCost);
            }
        }
        return cost%M;
    }
};