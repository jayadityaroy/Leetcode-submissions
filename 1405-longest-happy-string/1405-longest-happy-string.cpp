// Brute force approach:
class Solution {
public:
    string longestDiverseString(int a, int b, int c) {
        typedef pair<int, char> P;
        priority_queue<P, vector<P>> maxHeap;
        if(a > 0) maxHeap.push({a, 'a'});
        if(b > 0) maxHeap.push({b, 'b'});
        if(c > 0) maxHeap.push({c, 'c'});
        string ans = "";
        while(maxHeap.size() >= 2){
            if(ans.size() >= 2 && ans.back() == ans[ans.size()-2]){
                int lastChar = ans.back();
                auto t = maxHeap.top();
                maxHeap.pop();
                if(lastChar == t.second){
                    //maxHeap.pop();
                    auto t2 = maxHeap.top(); maxHeap.pop(); maxHeap.push(t);
                    ans += t2.second;
                    t2.first--;
                    if(t2.first > 0) maxHeap.push(t2);
                }
                else{
                    //auto t = maxHeap.top(); maxHeap.pop();
                    ans += t.second;
                    t.first--;
                    if(t.first > 0) maxHeap.push(t);
                }
            }
            else{
                auto t = maxHeap.top(); maxHeap.pop();
                ans += t.second;
                t.first--;
                if(t.first > 0) maxHeap.push(t);
            }
        } 
        while(!maxHeap.empty()){
            auto t = maxHeap.top();
            maxHeap.pop();
            if(ans.size() >= 2 && ans.back() == ans[ans.size()-2]){
                if(t.second == ans.back()) break;
                else{
                    ans += t.second;
                    t.first--;
                    if(t.first > 0) maxHeap.push(t);
                }
            }
            else{
                ans += t.second;
                t.first--;
                if(t.first > 0) maxHeap.push(t);
            }
        }
        return ans;     
    }
};