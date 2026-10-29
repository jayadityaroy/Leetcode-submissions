class Solution {
public:
    int findEndIndOfSubStr(int i, vector<int>& first, vector<int>& last, string& s){
        int endI = last[s[i]-'a']; // last occurence of s[i] is assumed to be the end of the current substr
        for(int j = i+1; j <= endI; j++){
            if(first[s[j]-'a'] < i) return -1; // not possible to form valid subsr if previous occ of s[j] < i
            endI = max(endI, last[s[j]-'a']); // expanding each character's range if necessary (if another character exists in the range with smaller/larger starting/ending index) 
        }
        return endI;
    }
    vector<string> maxNumOfSubstrings(string s) {
        int n = s.size();
        vector<int> first(26, -1); // first[s[i]-'a'] => first occ of s[i]
        vector<int> last(26, -1); // last[s[i]-'a'] => last occ of s[i]
        for(int i = 0; i < n; i++){
            int charInd = s[i]-'a';
            if(first[charInd] == -1) first[charInd] = i;
            last[charInd] = i;
        }
        vector<string> validSubStr;
        int lastEndI = -1; // ending ind of the last inserted valid substr
        for(int i = 0; i < n; i++){
            int charInd = s[i]-'a';
            if(i == first[charInd]){ // can't form valid substr, if 'i' is not the first occ of s[i]
                int currEndI = findEndIndOfSubStr(i, first, last, s); // ending of this substr (if valid)
                if(currEndI != -1){ // if curr substr is valid
                    // Case 1: This new substring is entirely inside the last one we found
                    // Since we want the SHORTEST possible substrings to maximize count, 
                    // we replace the previous one with this smaller one.
                    if(lastEndI >= i){
                        validSubStr.back() = s.substr(i, currEndI-i+1);
                    }
                    // Case 2: This substring starts after the previous one ends
                    else{
                        validSubStr.push_back(s.substr(i, currEndI-i+1));
                    }
                    lastEndI = currEndI;
                }
            }
        }
        return validSubStr;
    }
};