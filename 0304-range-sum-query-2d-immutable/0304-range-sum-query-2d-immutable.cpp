// Brute force:
class NumMatrix {
private:
    int M, N;
    int cummuSum[201][201];
    bool valueFound[201][201];
    int helperFun(vector<vector<int>>& matrix, int i, int j){
        if(i >= M || j >= N) return 0;
        if(valueFound[i][j] != false) return cummuSum[i][j];
        int diag = helperFun(matrix, i+1, j+1);
        int down = helperFun(matrix, i+1, j);
        int right = helperFun(matrix, i, j+1);
        valueFound[i][j] = true;
        return cummuSum[i][j] = matrix[i][j] + down + right - diag;
    }
public:
    NumMatrix(vector<vector<int>>& matrix) {
        M = matrix.size(); N = matrix[0].size();
        memset(cummuSum, 0, sizeof(cummuSum));
        memset(valueFound, false, sizeof(valueFound));
        helperFun(matrix, 0, 0);
    }
    
    int sumRegion(int row1, int col1, int row2, int col2) {
        int unionSum = cummuSum[row1][col1];
        int common1 = 0, common2 = 0, common3 = 0;
        if(row2+1 < M) common1 = cummuSum[row2+1][col1];
        if(col2+1 < N) common2 = cummuSum[row1][col2+1];
        if(row2+1 < M && col2+1 < N) common3 = cummuSum[row2+1][col2+1];
        return unionSum - common1 - common2 + common3;
    }
};

/**
 * Your NumMatrix object will be instantiated and called as such:
 * NumMatrix* obj = new NumMatrix(matrix);
 * int param_1 = obj->sumRegion(row1,col1,row2,col2);
 */