class Solution {
public:

    int ftd(int n){
        if(n==1 || n==0) return 1;
        if(n==2) return 2;

        int sum=0;
        for(int k=1;k<=n;k++){
            // k-> potential node
            sum+=ftd(k-1)*ftd(n-k);
        }
        return sum;

    }
    int numTrees(int n) {
        return ftd(n);
    }
};