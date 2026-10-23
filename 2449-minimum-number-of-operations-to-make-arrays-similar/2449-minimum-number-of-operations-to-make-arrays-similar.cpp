// Brute force approach:
// even can be converted to even and odd to odd
class Solution {
public:
    long long makeSimilar(vector<int>& nums, vector<int>& target) {
        int n = target.size();
        vector<int>evenNums, evenTarget;
        for(int i = 0; i < n; i++){
            if(nums[i]%2 == 0)evenNums.push_back(nums[i]);
        }
        for(int i = 0; i < n; i++){
            if(target[i]%2 == 0)evenTarget.push_back(target[i]);
        }
        vector<int>oddNums, oddTarget;
        for(int i = 0; i < n; i++){
            if(nums[i]%2 != 0) oddNums.push_back(nums[i]);
        }
        for(int i = 0; i < n; i++){
            if(target[i]%2 != 0) oddTarget.push_back(target[i]);
        }
        sort(evenNums.begin(), evenNums.end());
        sort(evenTarget.begin(), evenTarget.end());
        sort(oddNums.begin(), oddNums.end());
        sort(oddTarget.begin(), oddTarget.end());
        // solve for even elements:
        long long opCounts = 0;
        for(int i = 0; i < evenNums.size(); i++){
            int diff = abs(evenNums[i]-evenTarget[i]);
            opCounts += (diff/2);
        }
        // solve for odd elements:
        for(int i = 0; i < oddNums.size(); i++){
            int diff = abs(oddNums[i]-oddTarget[i]);
            opCounts += (diff/2);
        }
        return opCounts/2;
    }
};