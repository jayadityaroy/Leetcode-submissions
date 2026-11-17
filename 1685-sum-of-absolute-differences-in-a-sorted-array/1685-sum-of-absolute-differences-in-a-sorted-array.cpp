class Solution {
public:
    vector<int> getSumAbsoluteDifferences(vector<int>& nums) {
        int n = nums.size();
        // prefix sum:
        vector<int> pre(n, 0);
        for(int i = 1; i < n; i++){
            pre[i] = nums[i-1] + pre[i-1];
        }
        // postfix sum:
        vector<int> post(n, 0);
        for(int i = n-2; i >= 0; i--){
            post[i] = nums[i+1] + post[i+1];
        }
        vector<int> ans(n);
        for(int i = 0; i < n; i++){
            ans[i] = (nums[i]*i - pre[i]) + (post[i] - nums[i]*(n-i-1));
        }
        return ans;
    }
};