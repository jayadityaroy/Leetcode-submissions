class Solution {
public:
    string removeDuplicateLetters(string s) {
        int n = s.size();
        vector<int> lastOcc(26);
        vector<bool> taken(26, false);
        for(int i = 0; i < n; i++){
            lastOcc[s[i]-'a'] = i;
        }
        string result;
        for(int i = 0; i < n; i++){
            int ch = s[i];
            int chIdx = s[i] - 'a';
            if(taken[chIdx]) continue;
            while(!result.empty() && result.back() > ch && lastOcc[result.back()-'a'] > i){
                taken[result.back()-'a'] = false;
                result.pop_back();
            }
            result.push_back(ch);
            taken[chIdx] = true;
        }
        return result;
    }
};