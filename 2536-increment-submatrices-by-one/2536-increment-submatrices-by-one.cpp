// Difference array technique:
class Solution {
public:
    vector<vector<int>> rangeAddQueries(int n, vector<vector<int>>& queries) {
        vector<vector<int>> diffArr(n, vector<int>(n, 0));
        for(int i = 0; i < queries.size(); i++){
            int r1 = queries[i][0], r2 = queries[i][2];
            int c1 = queries[i][1], c2 = queries[i][3];
            for(int r = r1; r <= r2; r++){
                diffArr[r][c1]++;
                if(c2+1 < n){
                    diffArr[r][c2+1]--;
                }
            }
        }
        for(int i = 0; i < n; i++){
            for(int j = 1; j < n; j++){
                diffArr[i][j] = diffArr[i][j] + diffArr[i][j-1];
            }
        }
        return diffArr;
    }
};