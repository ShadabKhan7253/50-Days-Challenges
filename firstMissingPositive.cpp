#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

// Using Hashing
// Time : O(N)
// Space : O(N) 

// int firstMissingPositive(vector <int> nums) {
//     int n = nums.size();
//     unordered_map <int,bool> map;
//     for(int i=1;i<=n;i++) {
//         map[i] = false;
//     }
//     for(int i=0;i<n;i++) {
//         if(nums[i] > 0 && nums[i] <= n) {
//             map[nums[i]] = true;
//         }
//     }

//     for(int i=1;i<=n;i++) {
//         if(!map[i])
//             return i;
//     }
//     return n + 1;
// }

// Time : O(N)
// Space : O(1) 

int firstMissingPositive(vector <int> nums) {
    int n = nums.size();
    for(int i=0;i<n;i++) {
        int element = nums[i];
        if(element >= 1 && element <= n) {
            int chair = element - 1;
            if(nums[chair] != element) {
                swap(nums[chair],nums[i]);
                i--;
            }
        } 
    }

    for(int i=0;i<n;i++) {
        if(i+1 != nums[i]) return i+1;
    }
    return n+1;
}

int main() {
    vector <int> nums = {-5};
    int res = firstMissingPositive(nums);
    cout<<res;
    return 0;
}