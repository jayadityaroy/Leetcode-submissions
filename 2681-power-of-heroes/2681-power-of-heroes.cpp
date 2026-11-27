// Approach:
// sort nums
// fix the maxi element
// ultimate ans += maxi^2 * previous element's contribution as mini elements + maxi^3
class Solution {
public:
    int sumOfPower(vector<int>& nums) {
        int n = nums.size(), M = 1e9+7;
        sort(nums.begin(), nums.end());
        long long ans = 0;
        long long prevContri = 0; // contribution of all the previous elements(as a min) before the current elements
        for(int maxi = 0; maxi < n; maxi++){
            ans = (ans + ((((long long)nums[maxi]*nums[maxi])%M) * nums[maxi])%M)%M; // when maxi is the only element
            ans = (ans + ((((long long)nums[maxi]*nums[maxi])%M) * prevContri)%M)%M;
            prevContri = ((prevContri*2)%M + nums[maxi])%M; // include current element for the next element
        }
        return (int)ans;
    }
};