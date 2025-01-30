class Solution {
public:
    int trap(vector<int>& height) {
        int n=height.size();
        int trap=0;
        int arr[n];
        arr[0]=-1;
        int max2=height[0];
        for(int i=1;i<n;i++){
            arr[i]=max2;
            if(max2<height[i]) max2=height[i];
        }
        int brr[n];
        brr[n-1]=-1;
        int max1=height[n-1];
        for(int i=n-2;i>=0;i--){
            brr[i]=max1;
            if(max1<height[i]) max1=height[i];
        }
        for(int i=0;i<n;i++){
            brr[i]=min(arr[i],brr[i]);
        }
        for(int i=0;i<n;i++){
            if(brr[i]>height[i]) trap+=brr[i]-height[i];
        }
        return trap;

    }
};