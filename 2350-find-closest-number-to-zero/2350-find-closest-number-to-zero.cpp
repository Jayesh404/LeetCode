class Solution {
public:
    int findClosestNumber(vector<int>& nums) {
        int ans=0;
        int minDiff=INT_MAX;
        for(int i=0;i<nums.size();i++){
            if(abs(nums[i]-0)<minDiff){
                ans=nums[i];
                minDiff=abs(nums[i]-0);
            }
            else if (abs(nums[i]-0)==minDiff){
                if(nums[i]>ans) ans=nums[i];
                minDiff=abs(nums[i]-0);
            }
            else continue;
        }

        return ans;
    }
};