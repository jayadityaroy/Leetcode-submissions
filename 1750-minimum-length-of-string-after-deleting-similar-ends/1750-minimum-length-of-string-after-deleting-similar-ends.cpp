// Brute force approach:
class Solution {
public:
    int minimumLength(string s) {
        int n = s.size();
        int left = 0, right = n-1;
        while(left < right){
            if(s[left] == s[right]){
                char ch = s[left];
                int l = left+1, r = right-1;
                while(l < n && s[l] == ch){
                    l++;
                }
                left = l;
                if(left > right) break;
                while(r >= 0 && s[r] == ch){
                    r--;
                }
                right = r;
            }
            else break;
        }
        if(right >= left) return right-left+1;
        else return 0;
    }
};