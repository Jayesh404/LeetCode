class Solution {
public:
    int smallestNumber(int n) {
        int arr[]={1,3,7,15,31,63,127,255,511,1023};
        for(int i=0;i<10;i++){
            if(arr[i]>=n) return arr[i];
        }

        //  int x = 1;
        // while (x < n) {
        //     x = x * 2 + 1;
        // }
        // return x;

        return 0;
    }
};