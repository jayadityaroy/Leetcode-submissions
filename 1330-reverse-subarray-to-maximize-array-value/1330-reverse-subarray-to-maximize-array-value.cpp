// IDEA: reversing [l, r] never changes the cost INSIDE the subarray.
//       Only the two boundary hops change:
//         old hops: (a,b) and (c,d)   where a=nums[l-1], b=nums[l], c=nums[r], d=nums[r+1]
//         new hops: (a,c) and (b,d)
//       gain = |a-c| + |b-d| - |a-b| - |c-d|
//
// CASES:
//   1) prefix  (l = 0)  -> only the right boundary exists, brute force over r
//   2) suffix  (r = n-1)-> only the left boundary exists, brute force over l
//   3) middle           -> both boundaries exist, use the gap trick below
//
// GAP TRICK (middle case):
//   View each old hop as an interval [low, high] on the number line.
//   If two intervals are DISJOINT (one fully above the other):
//       gain = 2 * (low of upper interval - high of lower interval) = 2 * gap
//   If they overlap (gap <= 0): gain <= 0, so ignore.
//   Best gap = (largest low over all hops) - (smallest high over all hops)
//            = maxiLow - miniHigh      (one O(n) pass; both can come from different hops)
//
// ANSWER = oldVal + max(0, prefix gain, suffix gain, 2*gap)
// Time O(n), Space O(1)
class Solution {
public:
    int maxValueAfterReverse(vector<int>& nums) {
        int n = nums.size(), oldVal = 0;
        // old value:
        for(int i = 0; i < n-1; i++){
            oldVal += abs(nums[i]-nums[i+1]);
        }
        // max/best gain:
        int bestGain = 0;
        // prefix case:
        for(int r = 0; r < n-1; r++){
            int gain = abs(nums[0]-nums[r+1])-abs(nums[r]-nums[r+1]);
            bestGain = max(bestGain, gain);
        }
        // suffix case:
        for(int l = 1; l < n-1; l++){
            int gain = abs(nums[n-1]-nums[l-1])-abs(nums[l]-nums[l-1]);
            bestGain = max(bestGain, gain);
        }
        // subarray is at middle:
        int maxiLow = -1e9, miniHigh = 1e9; // maximum possible low, and minimum possible high
        for(int i = 0; i < n-1; i++){
            int low = min(nums[i], nums[i+1]); // lowest point in the interval
            int high = max(nums[i], nums[i+1]); // highest point in the interval
            maxiLow = max(maxiLow, low); 
            miniHigh = min(miniHigh, high);
        }
        int gap = (maxiLow - miniHigh);
        if(gap > 0){ // gap < 0 => overlap
            bestGain = max(bestGain, 2*gap);
        }
        return oldVal + bestGain;

    }
};