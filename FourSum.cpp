#include <iostream>
#include <vector>
#include <set>
#include <algorithm>

using namespace std;

// Brute Force :
// Time : O(n^4)

// vector<vector<int>> fourSum(vector<int>& nums, int target) {
//     int n = nums.size();
//     sort(nums.begin(), nums.end());
//     set<vector<int>> set;
//     vector<vector<int>> output;
//     for(int i=0; i<n-3; i++){
//         for(int j=i+1; j<n-2; j++){
//             for(int k=j+1; k<n-1; k++){
//                 for(int l=k+1; l<n; l++){
//                     if((long long)nums[i] + (long long)nums[j] + (long long)nums[k] + (long long)nums[l] == target){
//                         set.insert({nums[i], nums[j], nums[k], nums[l]});
//                     }
//                 }
//             }
//         }
//     }
//     for(auto it : set){
//         output.push_back(it);
//     }
//     return output;
// }


vector<vector<int>> fourSum(vector<int>& nums, int target) {
    int n = nums.size();
    sort(nums.begin(), nums.end());
    vector<vector<int>> output;
    for(int i=0; i<n-3; i++){
        for(int j=i+1; j<n-2; j++){
            long long newTarget = (long long)target - (long long)nums[i] - (long long)nums[j];
            int low = j+1, high = n-1;
            while(low < high){
                if(nums[low] + nums[high] < newTarget){
                    low++;
                }
                else if(nums[low] + nums[high] > newTarget){
                    high--;
                }
                else{
                    output.push_back({nums[i], nums[j], nums[low], nums[high]});
                    int tempIndex1 = low, tempIndex2 = high;
                    while(low < high && nums[low] == nums[tempIndex1]) low++;
                    while(low < high && nums[high] == nums[tempIndex2]) high--;
                }
            }
            while(j+1 < n && nums[j] == nums[j+1]) j++;
        }
        while(i+1 < n && nums[i] == nums[i+1]) i++;
    }
    return output;
}

int main() {
    vector <int> nums = {1,0,-1,0,-2,2};
    int target = 0;
    vector<vector<int>> res = fourSum(nums,target);
    for(auto list : res) {
        for(auto item : list) {
            cout<<item<<" ";
        }
        cout<<endl;
    }
}