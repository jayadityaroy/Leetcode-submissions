class Solution {
public:
    int countBinarySubstrings(string s) {
        int n = s.size();
        int subsetCount = 0, i = 0;
        while(i < n){
            int signACount = 1, j = i+1;
            while(j < n && s[j] == s[i]){
                signACount++;
                j++;
            }
            int nextI = j, signBCount = 0;
            while(j < n && s[j] != s[i]){
                signBCount++;
                j++;
            }
            subsetCount += min(signBCount, signACount);
            i = nextI;
        }
        return subsetCount;
    }
};