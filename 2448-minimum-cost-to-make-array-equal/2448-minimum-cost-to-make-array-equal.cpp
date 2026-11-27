// approach: try to convert every elements into a middle element
class Solution {
public:
    long long findCost(vector<int>& nums, vector<int>& cost, int target){
        long long tot = 0;
        for(int i = 0; i < nums.size(); i++){
            tot += (long long)abs(nums[i]-target)*cost[i];
        }
        return tot;
    }
    long long minCost(vector<int>& nums, vector<int>& cost) {
        int n = nums.size();
        int maxi = *max_element(begin(nums), end(nums));
        int mini = *min_element(begin(nums), end(nums));
        // use binary search to find the middle element:
        long long ans = LONG_MAX;
        while(mini <= maxi){
            int mid = mini + (maxi-mini)/2;
            long long costMid = LONG_MAX, costRight = LONG_MAX;
            costMid = findCost(nums, cost, mid);
            costRight = findCost(nums, cost, mid+1);
            ans = min({ans, costMid, costRight});
            if(costRight > costMid){
                maxi = mid-1;
            }
            else{
                mini = mid+1;
            }
        }
        return ans == LONG_MAX? 0: ans;
    }
};