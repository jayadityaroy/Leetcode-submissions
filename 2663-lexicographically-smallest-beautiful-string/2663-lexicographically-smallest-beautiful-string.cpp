// Approach:
// 1. Traverse 's' from left to right and find the first character (let it be at index 'i') that can be replaced with greater character within range 'a'+k, and replace it
// 2. After replacing the character at index 'i', replace the character from index i+1 to n-1, with smaller characters
// 3. while replacing make sure that the replaced character is not same as in index i-1 and i-2 (making sure 2 and 3 length pallindromes are not formed)
class Solution {
public:
    bool check(string& str, int i, char rep){
        if(i-1 >= 0 && str[i-1] == rep) return false;
        if(i-2 >= 0 && str[i-2] == rep) return false;
        return true;
    }
    string smallestBeautifulString(string s, int k) {
        int n = s.size();
        string ans = s;
        for(int i = n-1; i >= 0; i--){
            // try replacing at i with different characters
            for(char replacement = ans[i]+1; replacement < 'a'+k; replacement++){
                if(check(ans, i, replacement)){ // if replacing with replacement doesn't form pallindrome
                    ans[i] = replacement;
                    // replace next characters
                    for(int j = i+1; j < n; j++){
                        for(char replacement2 = 'a'; replacement2 < 'a'+k; replacement2++){
                            if(check(ans, j, replacement2)){
                                ans[j] = replacement2;
                                break;
                            }
                        }
                    }
                    return ans;
                }
            }
        }
        return "";
    }
};