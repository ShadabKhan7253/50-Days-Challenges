#include <iostream>
#include <vector>

using namespace std;

int maximumSubArray(vector <int> &nums) {
    int currentMax = nums[0];
    int maximumSum = nums[0];
    for(int i=1;i<nums.size();i++) {
        currentMax = max(currentMax + nums[i], nums[i]);
        maximumSum = max(maximumSum, currentMax);
    }
    return maximumSum;
}

int main() {
    vector <int> nums = {-2,1,-3,4,-1,2,1,-5,4};
    int res = maximumSubArray(nums); 
    cout<<res<<endl;
}