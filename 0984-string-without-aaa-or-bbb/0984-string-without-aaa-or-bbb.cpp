// Brute force approach:
class Solution {
public:
    string strWithout3a3b(int a, int b) {
        int n = a+b;
        string ans = "";
        while(a > 0 && b > 0 && a > b){
            ans.push_back('a'); a--;
            if(a > 0){
                ans.push_back('a');
                a--;
            }
            if(b > 0){
                ans.push_back('b');
                b--;
            }
        }
        while(a > 0 && b > 0 && b > a){
            ans.push_back('b'); b--;
            if(b > 0){
                ans.push_back('b');
                b--;
            }
            if(a > 0){
                ans.push_back('a');
                a--;
            }
        }
        while(a > 0 && b > 0){
            if(ans.empty() || ans.back() == 'a'){
                ans.push_back('b');
                b--;
                ans.push_back('a');
                a--;
            }
            else{
                ans.push_back('a');
                a--;
                ans.push_back('b');
                b--;
            }
        }
        while(a > 0){
            ans.push_back('a');
            a--;
        }
        while(b > 0){
            ans.push_back('b');
            b--;
        }
        return ans;
    }
};