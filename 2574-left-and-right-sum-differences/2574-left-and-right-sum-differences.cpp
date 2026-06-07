class Solution {
public:
    vector<int> leftRightDifference(vector<int>& nums) {
        vector<int> answer(nums.size());
        int n=nums.size();
        vector<int> left(n),right(n);
        for(int i=1;i<n;i++){
            left[i]=left[i-1]+nums[i-1];
        }
        for(int i=n-2;i>=0;i--){
            right[i]=right[i+1]+nums[i+1];
        }
        for(int i=0;i<n;i++){
            answer[i]=abs(left[i]-right[i]);
        }
        return answer;
    }
};