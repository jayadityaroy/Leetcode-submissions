class Solution {
public:
    vector<int> prevPermOpt1(vector<int>& arr) {
        vector<int> ans = arr;
        int n = arr.size();
        for(int i = n-1; i >= 0; i--){
            int maxi = -1e9, maxiInd = -1;
            bool flag = false;
            for(int j = i+1; j < n; j++){
                if(ans[j] < ans[i] && maxi < ans[j]){
                    maxi = ans[j];
                    maxiInd = j;
                    flag = true;
                }
            }
            if(flag){
                swap(ans[maxiInd], ans[i]);
                break;
            }
        }
        return ans;
    }
};