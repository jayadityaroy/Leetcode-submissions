class Solution {
public:
    int compress(vector<char>& chars) {
        int index = 0;
        int i = 0;
        int n = chars.size();

        while(i < n){
            char curr_char = chars[i];
            int char_count = 0;

            while ( i < n && chars [i] == curr_char){
                char_count++;
                i++;
            
            }

            chars[index] = curr_char;
            index++;
            if(char_count > 1){
                string count_str = to_string(char_count);
                for(char &c: count_str){
                    chars[index] = c;
                    index++;
                }
            }
        }
        return index;
        
    }
};