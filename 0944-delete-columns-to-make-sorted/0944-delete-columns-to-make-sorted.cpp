class Solution {
public:
    int minDeletionSize(vector<string>& strs) {
        int n=strs.size();
        int m=strs[0].size();

        int count=0;

        for(int j=0;j<m;j++){
            bool flag=false;
            for(int i=1;i<n;i++){
                if(strs[i-1][j]>strs[i][j]){
                    flag=true;
                    count++;
                    break;
                }
            }
            if(flag) continue;
        }
        return count;
    }
};