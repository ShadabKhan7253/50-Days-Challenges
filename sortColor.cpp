#include <iostream>
#include <vector>

using namespace std;

vector <int> sortColor(vector <int> &nums) {
    int i=0;
    int j=0;
    int n = nums.size() - 1;
    while(j<=n) {
        if(nums[j] < 1) {
           swap(nums[i++],nums[j++]); 
        } else if(nums[j] > 1) {
            swap(nums[j],nums[n--]);
        } else {
            j++;
        }
    }
    return nums;
}

int main() {
    vector <int> nums = {2,0,2,1,1,0};
    vector <int> res = sortColor(nums);
    for (int item : res) 
        cout<<item<<" ";
    return 0;
}