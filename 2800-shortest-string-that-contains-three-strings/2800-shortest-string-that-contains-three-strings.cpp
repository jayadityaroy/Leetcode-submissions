class Solution {
public:
    // find the minimum string out of two:
    string findMin(string s1, string s2){
        return (s1.size() < s2.size() || (s1.size() == s2.size() && s1 < s2))? s1: s2;
    }
    // add two string optimally (resultant string is of minimum length):
    string addOptimally(string& s1, string& s2){
        //One string is already a substring of another string
        if(s2.find(s1) != string::npos) return s2;
        // One string's back side sub-string is common with another string's front side sub-string (here, back side starting from first index, thus also checking for s2 is already a substr of s1)
        for(int i = 0; i < s1.size(); i++){
            string t1 = s1.substr(i), t2 = s2.substr(0, t1.size());
            if(t1 == t2) return s1 + s2.substr(t1.size());
        }
        return s1+s2;
    }
    string solve(string& a, string& b, string& c){
        string t1 = addOptimally(a, b), t2 = addOptimally(b, a);
        string res1 = findMin(addOptimally(t1, c), addOptimally(c, t1));
        string res2 = findMin(addOptimally(t2, c), addOptimally(c, t2));
        return findMin(res1, res2);
    }
    string minimumString(string a, string b, string c) {
        string t1 = solve(a, b, c);
        string t2 = solve(b, c, a);
        string t3 = solve(c, a, b);
        return findMin(findMin(t1, t2), t3);
    }
};