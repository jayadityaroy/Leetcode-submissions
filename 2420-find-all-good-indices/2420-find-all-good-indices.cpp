class Solution {
public:
    vector<int> goodIndices(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int> nonIncrease(n, 1); // no.of eles in the left (including it self) are non-increasing
        for(int i = 1; i < n; i++){
            if(nums[i-1] >= nums[i]){
                nonIncrease[i] = nonIncrease[i-1]+1;
            }
        }
        for(const auto& i: nonIncrease){
            cout<<i<<", ";
        }
        cout<<endl;
        vector<int> nonDecrease(n, 1);
        for(int i = n-2; i >= 0; i--){ // no.of eles in the right (including it self) are non-decreasing
            if(nums[i] <= nums[i+1]){
                nonDecrease[i] = nonDecrease[i+1]+1;
            }
        }
        for(const auto& d: nonDecrease){
            cout<<d<<", ";
        }
        cout<<endl;
        vector<int> ans;
        for(int i = k; i < n-k; i++){
            if(nonIncrease[i-1] >= k && nonDecrease[i+1] >= k)     
                ans.push_back(i);
        }
        return ans;
    }
};