// Optimised approach:
// the order of the L’s and R’s, with blanks removed, must be identical in both strings
class Solution {
public:
    bool canChange(string start, string target) {
        int i = 0, j = 0, n = start.size();
        while(i < n && j < n){
            if(start[i] == '_') i++;
            else if(target[j] == '_') j++;
            else if(target[j] == start[i]){
                if(start[i] == 'L'){
                    if(j > i) return false; // L pieces can't reach to the right
                }
                else{
                    if(j < i) return false; // R pieces can't reach to the left
                }
                i++; j++;
            }
            else return false;
        }
        // check if there is any left over pieces
        while(j < n){
            if(target[j] == 'L' || target[j] == 'R') return false;
            j++;
        }
        while(i < n){
            if(start[i] == 'L' || start[i] == 'R') return false;
            i++;
        }
        return true;
    }
};