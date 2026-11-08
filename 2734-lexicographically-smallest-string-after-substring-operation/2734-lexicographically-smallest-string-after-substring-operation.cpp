class Solution {
public:
    string smallestString(string s) {
        if(s=="a") return "z";
        int n = s.size();
        int i;
        bool flag = false;// true if changes occured in s
        for(i = 0; i < n; i++){
            if(s[i] == 'a' ){
                int j = i+1;
                while(j < n && s[j] == 'a'){
                    j++;
                }
                i = j;
                break;
            }
            else{
                s[i] = s[i]-1;
                flag = true;
            }
        }
        if(flag == false){
            if(i < n){
                while(i < n && s[i] != 'a'){
                    s[i] = s[i]-1;
                    i++;
                }
            }
            else{
                s[n-1] = 'z';
            }
        }
        // i = i+1; // if i is pointing at 'a'
        // if(!flag){ // no changes occured => 'a' at 0th index
        //     while(i < n){
        //         if(s[i] )
        //         i++;
        //     }
        // }
        // if(!flag && i >= n){ // still no changes => all elements are 'a'
        //     s[n-1] = 'z'; // changes the last 'a'
        // }
        return s;
    }
};