class Solution {
public:
    int minPatches(vector<int>& nums, int n) {
        long long maxReach = 0; // current range: [1, maxReach]
        long long miss = maxReach+1; // number that can't be reached currently
        int i = 0, patchCount = 0;
        while(maxReach < n){
            if(i < nums.size() && miss >= nums[i]){
                maxReach += nums[i++];
                miss = maxReach+1;
            }
            else{ // nums[i] > miss => can't add upto number- miss => patch miss (greedy)
                patchCount++;
                maxReach += miss;
                miss = maxReach+1;
            }
        }
        return patchCount;
    }
};