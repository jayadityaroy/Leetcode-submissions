class NumArray {
public:
    vector<int> prefixSum;
    vector<int> classNums;
    NumArray(vector<int>& nums) {
        classNums = nums;
        prefixSum.resize(nums.size(), 0);
        prefixSum[0] = nums[0];
        for(int i = 1; i < nums.size(); i++){
            prefixSum[i] = prefixSum[i-1]+nums[i];
        }
    }
    
    int sumRange(int left, int right) {
        return prefixSum[right]-prefixSum[left]+classNums[left];
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * int param_1 = obj->sumRange(left,right);
 */