class Solution {
public:
    int getOddNumbers(int n)
    {
        return (n>>1) + (n&1);
    }
    int getEvenNumbers(int n)
    {
        return n>>1;
    }
    long long flowerGame(int n, int m) {
        long long ans = 0;
        ans = 1l*getOddNumbers(n)*getEvenNumbers(m) + 1l*getEvenNumbers(n)*getOddNumbers(m);
        return ans;
    }
};