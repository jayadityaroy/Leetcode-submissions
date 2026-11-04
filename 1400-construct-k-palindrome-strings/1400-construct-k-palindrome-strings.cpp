// Approach: the minimum number of pallindromes we can make from s depends upon the number of characters that have odd freq, if there are 3 character with odd freq => minimum 3 pallinrdromes possible
class Solution {
public:
    bool canConstruct(string s, int k) {
        int n = s.size();
        if(n < k) return false; // maximum n pallindromes can be formed from s with n characters
        if(n == k) return true;
        vector<int> freq(26, 0);
        for(int i = 0; i < n; i++){
            int charInd = s[i]-'a';
            freq[charInd]++;
        }
        int oddFreqCount = 0;
        for(int i = 0; i < 26; i++){
            if(freq[i] % 2 != 0) oddFreqCount++;
        }
        return oddFreqCount <= k;  
    }
};