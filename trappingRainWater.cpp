#include <iostream>
#include <vector>

using namespace std;

//BRUTE FORCE
//Time: O(n^2)
//Space: O(1)

// int trap(vector <int> nums) {
//     int res=0;
//     for(int i=1;i<nums.size();i++) {
//         int left = nums[i];
//         for(int j=0;j<i;j++)
//             left = max(left,nums[j]);
//         int right = nums[i];
//         for (int j=i+1;j<nums.size();j++)
//             right = max(right,nums[j]);
//         res = res + min(left,right) - nums[i];
//     }
//     return res;
// }

//int trap(vector <int>& nums) {
//    int left = 0;
//    int right = 0;
//    int total = 0;
//
//    for(int i=1;i<nums.size();i++) {
//        left = i-1;
//        right = i+1;
//        while(left>=0) {
//            if(left == 0 && nums[left] > nums[i])
//                left = 0;
//            else if(nums[left] > nums[left-1])
//                break;
//            else
//                left--;
//        }
//        while(right<nums.size()) {
//            if(nums[right] > nums[right+1])
//                break;
//            right++;
//        }
//        int waterContain = min(nums[left],nums[right]) - nums[i];
//        total +=  waterContain;
//
//    }
//}



/*****************************************************************************
 * Precalculate the leftmax and rightmax and store in the left and right array *
******************************************************************************/
// Time: O(n)
// Space : O(n)

int trap(vector <int>& height) {
    vector <int> left(height.size());
    vector<int> right(height.size());
    int total = 0;

    left[0] = height[0];
    for(int i=1;i<height.size();i++) 
        left[i] = max(left[i-1],height[i]);

    right[height.size() - 1] = height[height.size() - 1];
    for(int i=height.size() - 2;i>=0;i--) 
        right[i] = max(right[i+1],height[i]);

    for(int i=1;i<height.size()-1;i++) {
        int currentWaterTrap = min(left[i-1],right[i+1]);
        if(currentWaterTrap > height[i]) total += currentWaterTrap - height[i];
    }
    return total;
}


/*************************************
 ******** Two Pointer Approach *******
**************************************/

// Time: O(n)
// Space : O(1)


//int trap(vector <int>& height) {
//    int left = 0;
//    int right = height.size() - 1;
//    int total = 0;
//    int leftMax = 0;
//    int rightMax = 0;
//
//    while(left < right) {
//        leftMax = max(leftMax,height[left]);
//        rightMax = max(rightMax,height[right]);
//
//        if(height[left] < height[right]) {
//            int currentWaterTrap = leftMax - height[left];
//            total += currentWaterTrap;
//            ++left;
//        } else {
//            int currentWaterTrap = rightMax - height[right];
//            total += currentWaterTrap;
//            --right;
//        }
//    }
//    return total;
//}



int main() {
    vector <int> nums = {0,1,0,2,1,0,1,3,2,1,2,1};
    int res = trap(nums);
    cout<<res<<endl;
    return 0;
}
