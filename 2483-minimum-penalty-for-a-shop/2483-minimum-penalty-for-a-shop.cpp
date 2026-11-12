class Solution {
public:
    int bestClosingTime(string customers) {
        int n = customers.size();
       vector<int> opened(n, 0);
       vector<int> closed(n, 0);
       for(int i = 0; i < n; i++){
            if(customers[i] == 'Y'){
                opened[i] = 0;
                closed[i] = 1;
            }
            else if(customers[i] == 'N'){
                opened[i] = 1;
                closed[i] = 0;
            }
       }
       vector<int> prefixOpened(n, 0);
       vector<int> prefixClosed(n, 0);
       prefixOpened[0] = opened[0];
       prefixClosed[0] = closed[0];
       for(int i = 1; i < n; i++){
            prefixOpened[i] = opened[i] + prefixOpened[i-1];
            prefixClosed[i] = closed[i] + prefixClosed[i-1];
       }
       int minPenalty = 1e9;
       int minTime = 1e9;
       // for closing at hour 0:
       minPenalty = prefixClosed[n-1] - prefixClosed[0] + closed[0];
       minTime = 0;
       // remaining hours:
       for(int i = 1; i < n; i++){
            int currPenalty = prefixOpened[i-1] + closed[i] + (prefixClosed[n-1]-prefixClosed[i]);
            if(minPenalty > currPenalty){
                minPenalty = currPenalty;
                minTime = i;
            }
       }
       // for closing at n-th hour:
       if(minPenalty > prefixOpened[n-1]){
            minTime = n;
       }
       return minTime;
    }
};