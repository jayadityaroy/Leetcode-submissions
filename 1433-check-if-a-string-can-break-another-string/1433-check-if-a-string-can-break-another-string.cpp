// Brute force approach:
class Solution {
public:
    bool checkIfCanBreak(string s1, string s2) {
        int n = s1.size();
        sort(s1.begin(), s1.end());
        sort(s2.begin(), s2.end());

        int i = 0, j = 0;
        while(i < n && j < n){
            if(s1[i] >= s2[j]){
                i++; j++;
            }
            else{
                j++;
            }
        }
        if(i >= n) return true; // s1 can break s2
        i = 0, j = 0;
        while(i < n && j < n){
            if(s2[i] >= s1[j]){
                i++; j++;
            }
            else{
                j++;
            }
        }
        if(i >= n) return true; // s2 can break s1
        else return false; // s2 can't break s1

        
    }
};