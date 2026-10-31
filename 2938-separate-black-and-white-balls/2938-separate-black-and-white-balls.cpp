class Solution {
public:
    long long minimumSteps(string s) {
        int n = s.size();
        int nextZeroPos = 0;
        long long swaps = 0;
        for(int i = 0; i < n; i++){
            if(s[i] == '0'){
                swaps += (i-nextZeroPos);
                nextZeroPos++;
            }
        }
        return swaps;
    }
};