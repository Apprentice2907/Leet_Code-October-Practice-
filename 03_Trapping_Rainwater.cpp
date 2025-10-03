// Given n non-negative integers representing an elevation map where the width of each bar is 1, compute how much water it can trap after raining.

 

// Example 1:


// Input: height = [0,1,0,2,1,0,1,3,2,1,2,1]
// Output: 6
// Explanation: The above elevation map (black section) is represented by array [0,1,0,2,1,0,1,3,2,1,2,1]. In this case, 6 units of rain water (blue section) are being trapped.
// Example 2:

// Input: height = [4,2,0,3,2,5]
// Output: 9







// Naive approach but time limit exceeded

class Solution {
public:
    int trap(vector<int>& height) {
        int n=height.size();
        int water = 0;
        for(int i =0;i<n;i++){
            int lmax=0,rmax=0;
            for(int j=0;j<=i;j++){
                lmax=max(lmax,height[j]);
            }
            for(int j=i;j<n;j++){
                rmax=max(rmax,height[j]);
            }
            water+=min(lmax,rmax)-height[i];
        }
        return water;
    }
};



// Optimal solution uisng two pointer approach

class Solution {
public:
    int trap(vector<int>& height) {
        int n = height.size();
        int ans=0;
        int l=0,r=n-1;
        int lmax=0,rmax=0;

        while(l<r){
            lmax=max(lmax,height[l]);
            rmax=max(rmax,height[r]);
            if(lmax<rmax){
                ans+=lmax-height[l];
                l++;
            }
            else{
                ans+=rmax-height[r];
                r--;
            }
        }
        return ans;
    }
};