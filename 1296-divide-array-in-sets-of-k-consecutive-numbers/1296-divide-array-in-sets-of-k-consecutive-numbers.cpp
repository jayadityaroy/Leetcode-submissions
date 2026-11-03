class Solution {
public:
    bool isPossibleDivide(vector<int>& nums, int k) {
        int n = nums.size();
        if(n%k != 0) return false;

        map<int,int> freq;
        for(const auto& num: nums){
            freq[num]++;
        } 
        for(const auto& [num, f]: freq){
            if(f == 0) continue;
            int need = f; // need atleast 'need' frequency for all the elements in the subarray
            int lastNum = k+num-1; // last number of the subarray
            for(int i = num; i <= lastNum; i++){
                if(freq.count(i) == 0 || freq[i] < need) return false;
                freq[i] = freq[i]-need;
            }
        }
        return true;
    }
};