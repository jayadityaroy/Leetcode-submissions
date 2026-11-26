class Solution {
public:
    int maxScore(vector<int>& cardPoints, int k) {
        int left = 0, right = cardPoints.size()-1, n = cardPoints.size(), sum = 0;
        vector<int> prefixSum(n, 0);
        prefixSum[0] = cardPoints[0];
        vector<int> suffixSum(n, 0);
        suffixSum[n-1] = cardPoints[n-1];
        for(int i = 1; i < n; i++){
            prefixSum[i] = cardPoints[i] + prefixSum[i-1];
        }
        for(int i = n-2; i >= 0; i--){
            suffixSum[i] = cardPoints[i] + suffixSum[i+1];
        }
        while(left <= right && k > 0){
            int leftSum = prefixSum[k + left - 1] - prefixSum[left] + cardPoints[left];
            int rightSum = suffixSum[right - k + 1] - suffixSum[right] + cardPoints[right];
            if(leftSum > rightSum){
                sum += cardPoints[left++];
            }
            else{
                sum+= cardPoints[right--];
            }
            k--;
        }
        return sum;
    }
};