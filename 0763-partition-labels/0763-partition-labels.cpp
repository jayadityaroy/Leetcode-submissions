class Solution {
public:
    int findEnd(string& s, int i, vector<int>& first, vector<int>& last){
        int end = last[s[i]-'a'];
        for(int j = i+1; j <= end; j++){
            end = max(end, last[s[j]-'a']);
        }
        return end;
    }
    vector<int> partitionLabels(string s) {
        int n = s.size();
        //find the first and the last occurence of the characters:
        vector<int> first(26, 26);
        vector<int> last(26, -1);
        for(int i = 0; i < n; i++){
            int charInd = s[i]-'a';
            if(first[charInd] != 26){
                last[charInd] = i;
            }
            else{
                first[charInd] = i;
                last[charInd] = i;
            }
        }
        vector<int> ans;
        int i = 0;
        while(i < n){
            int end = findEnd(s, i, first, last); // find the end of the part
            ans.push_back(end-i+1);
            i = end+1;
        }
        return ans;
    }
};