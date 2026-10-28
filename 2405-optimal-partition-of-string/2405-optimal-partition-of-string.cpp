// Brute force approach:
class Solution {
public:
    int partitionString(string s) {
        int n = s.size(), count = 0;
        int i = 0;
        while(i < n){
            vector<int> freq(26, 0);
            int j = i;
            while(j < n){
                if(freq[s[j]-'a'] == 1) break; // already present in substring
                freq[s[j]-'a']++;
                j++;
            }
            i = j;
            count++;
        }
        return count;
    }
};