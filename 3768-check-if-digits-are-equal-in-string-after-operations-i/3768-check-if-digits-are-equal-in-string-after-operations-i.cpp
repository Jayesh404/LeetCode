class Solution {
public:
    bool hasSameDigits(string s) {
        int operations=s.length()-2;
        string str=s;


        while(operations--){
            for(int i=1;i<str.length();i++){
                str[i-1]=(str[i-1]+str[i])%10;
            }
            str.pop_back();
        }

        return str[0]==str[1];
    }
};