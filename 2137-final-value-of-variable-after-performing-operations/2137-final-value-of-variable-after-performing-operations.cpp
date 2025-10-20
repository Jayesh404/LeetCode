class Solution {
public:
    int finalValueAfterOperations(vector<string>& operations) {
        int x=0;
        for(int i=0;i<operations.size();i++){
            string temp=operations[i];
            if(temp[0]=='+' || temp[2]=='+') x++;
            else x--;

        }
        return x;
    }
};