class Solution {
public:
    string smallestSubsequence(string s) {
        int n = s.size();
        vector<bool> taken(26, false);
        vector<int> lastOcc(26);
        for(int i =  0; i < n; i++){
            lastOcc[s[i]-'a'] = i;
        }
        string result;
        for(int i = 0; i < n; i++){
            int ch = s[i];
            int chIdx = s[i]-'a';
            if(taken[chIdx])continue;
            while(result.size() > 0 && result.back() > ch && lastOcc[result.back()-'a'] > i){
                taken[result.back()-'a'] = false;
                result.pop_back();
            }
            result.push_back(ch);
            taken[chIdx]=true;
        }
        return result;
    }
};