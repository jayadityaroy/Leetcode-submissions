class Solution {
public:
    string largestMerge(string w1, string w2) {
        int n1 = w1.size(), n2 = w2.size(), i = 0, j = 0;
        string merge;
        while(i < n1 && j < n2){
            if(w1[i] > w2[j]){
                merge.push_back(w1[i++]);
            }
            else if(w1[i] < w2[j]){
                merge.push_back(w2[j++]);
            }
            else{
                int a = i, b = j;
                while(a < n1 && b < n2 && w1[a] == w2[b]){
                    a++; b++;
                }
                if(a < n1 && b < n2 && w1[a] > w2[b]){
                    merge.push_back(w1[i++]);
                }
                else if(a < n1 && b < n2 && w1[a] < w2[b]){
                    merge.push_back(w2[j++]);
                }
                else if(a == n1 && b < n2){
                    merge.push_back(w2[j++]);
                }
                else if(a < n1 && b == n2){
                    merge.push_back(w1[i++]);
                }
                else{
                    merge.push_back(w1[i++]);// or push_back(w2[j++])
                }
            }
        }
        while(i < n1){
            merge.push_back(w1[i++]);
        }
        while(j < n2){
            merge.push_back(w2[j++]);
        }
        return merge;
    }
};