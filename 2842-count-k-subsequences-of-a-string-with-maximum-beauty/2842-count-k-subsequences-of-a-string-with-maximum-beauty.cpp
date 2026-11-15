class Solution {
public:
    int countKSubsequencesWithMaxBeauty(string s, int k) {
        vector<int>f(26, 0);
        for(int i = 0; i < s.size(); i++){
            f[s[i]-'a']++;
        }
        int uniqueCount = 0;
        for(int i = 0; i < 26; i++){
            if(f[i] > 0) uniqueCount++;
        }
        if(uniqueCount < k) return  0; // not possible if s has <k unique characters
        sort(f.begin(), f.end(), greater<int>());
        
        // Split the letters into 3 groups, using v = the k-th largest frequency:
        int i = 0;
        const int MOD = 1e9 + 7;
        // Bigger than v : they are always chosen. Multiply their frequencies.
        long long ans = 1;
        int v = f[k-1], vCount = 0;
        for(i = 0; i < 26; i++){
            if(f[i] <= v) break;
            ans = ans*f[i]%MOD;
            vCount++;
        }
        
        // Equal to v (b, c, d): let m = how many letters have frequency v, and r = how many of them you still need (r = 2). Choose which letters in C(m, r) ways, and each chosen letter contributes v, so v^r
        int m = 0;
        for(; i < 26; i++){
            if(f[i] < v) break;
            m++;
        }
        int r = k - vCount;
        for (int t = 0; t < r; t++) ans = ans * v % MOD;

        // chosse r letters from m letters in C(m, r) ways
        long long C[27][27] = {};   // zero-initialized
        for (int i = 0; i <= 26; i++) {
            C[i][0] = 1;                      // choosing 0 items: 1 way
            for (int j = 1; j <= i; j++) {
                C[i][j] = (C[i-1][j-1] + C[i-1][j]) % MOD;
            }
        }
        ans = ans * C[m][r] % MOD;

        //Smaller than v: never chosen.

        return ans;

    }
};