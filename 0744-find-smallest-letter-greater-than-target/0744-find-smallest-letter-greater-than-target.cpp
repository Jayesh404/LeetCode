class Solution {
public:
    char nextGreatestLetter(vector<char>& letters, char target) {
        char ans=letters[0];

        for(char ch: letters){
            if(ch>target){
                ans=ch;
                break;
            }
        }
        return ans;
    }
};