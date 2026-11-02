class Solution {
public:
    bool areSentencesSimilar(string sentence1, string sentence2) {
        int n1 = sentence1.size(), n2 = sentence2.size();
        if(n1 < n2){
            swap(sentence1, sentence2);
        }
        // store the sentences in vector as each words as elements
        vector<string> v1, v2;
        stringstream ss1(sentence1);
        string token;
        while(ss1 >> token){
            v1.push_back(token);
        }
        stringstream ss2(sentence2);
        while(ss2 >> token){
            v2.push_back(token);
        }

        int i = 0, j = v1.size()-1;
        int k = 0, l = v2.size()-1;
        while(i < v1.size() && k < v2.size() && v1[i]==v2[k]){
            i++; k++;
        }
        while(j >= 0 && l >= 0 && v1[j] == v2[l]){
            j--; l--;
        }
        return (k > l);
    }
};