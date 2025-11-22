class Solution {
public:
    int minimumOperations(vector<int>& nums) {
        int operations=0;
        for(int x: nums) operations+=min((x%3),3-(x%3));
        return operations;
    }
};