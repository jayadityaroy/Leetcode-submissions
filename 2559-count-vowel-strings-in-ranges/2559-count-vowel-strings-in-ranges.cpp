class Solution {
public:
    bool isVowel(char& letter){
        return(letter == 'a' || letter == 'e' || letter == 'i' || letter == 'o' || letter == 'u');
    }
    bool isAppt(string& word){
        return (isVowel(word[0]) && isVowel(word[word.size()-1]));
    }
    vector<int> vowelStrings(vector<string>& words, vector<vector<int>>& queries) {
        int nWords = words.size();
        int nQueries = queries.size();
        vector<int> prefixCount(nWords, 0);
        prefixCount[0] = isAppt(words[0]);
        for(int i = 1; i < nWords; i++){
            prefixCount[i] = prefixCount[i-1]+ isAppt(words[i]);
        }

        vector<int> ans;
        for(const auto& q: queries){
            int l = q[0], r = q[1];
            ans.push_back(prefixCount[r] - prefixCount[l] + isAppt(words[l]));
        }
        return ans;
    }
};