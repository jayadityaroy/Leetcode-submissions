class Solution {
public:
    string reorganizeString(string s) {
        typedef pair<int,char> P;
        int n = s.size();
        priority_queue<P, vector<P>> maxHeap;
        vector<int> freq(26, 0);
        for(int i = 0; i < n; i++){
            int charInd = s[i]-'a';
            freq[charInd]++;
            if(freq[charInd] > (n+1)/2) return ""; // not possible
        }
        for(char ch = 'a'; ch <= 'z'; ch++){
            if(freq[ch-'a'] > 0) maxHeap.push({freq[ch-'a'], ch});
        }
        string ans = "";
        while(maxHeap.size() >= 2){
            auto p1 = maxHeap.top(); maxHeap.pop();
            auto p2 = maxHeap.top(); maxHeap.pop();
            ans.push_back(p1.second); p1.first--;
            ans.push_back(p2.second); p2.first--;
            if(p1.first > 0) maxHeap.push(p1);
            if(p2.first > 0) maxHeap.push(p2);
        }
        if(!maxHeap.empty()){
            ans.push_back(maxHeap.top().second);
        }
        return ans;
    }
};