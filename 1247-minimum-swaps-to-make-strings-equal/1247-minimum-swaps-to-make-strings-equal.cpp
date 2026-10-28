// approach:
// Three cases:
// 1. "xx" and "yy" -> need 1 swap
// 2. "xy" and "yx" -> need 2 swap
// 3. "xx" and "yx" -> impossible/ -1
class Solution {
public:
    int minimumSwap(string s1, string s2) {
        int n = s1.size();
        int xyCount = 0, yxCount = 0;
        for(int i = 0; i < n; i++){
            if(s1[i] != s2[i]) {
                if(s1[i] == 'x') xyCount++;
                else yxCount++;
            }
        }
        int swaps = 0;
        int xyPairs = xyCount / 2;
        int xyExtra = xyCount % 2;
        int yxPairs = yxCount / 2;
        int yxExtra = yxCount % 2;
        if(xyExtra + yxExtra == 1) return -1; // not possible to equalize, if second pair is not there
        swaps += xyPairs; // case 1
        swaps += yxPairs; // case 1
        if(xyExtra + yxExtra == 2)swaps += 2; // case 2

        
        return swaps;
    }
};