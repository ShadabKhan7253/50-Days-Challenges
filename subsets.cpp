#include <iostream>
#include <vector>

using namespace std;

// void solve(vector <int> nums,vector <int> output, int index, vector<vector<int>> &result) {
//     if(index >= nums.size()) {
//         result.push_back(output);
//         return;
//     } 

//     // exclude
//     solve(nums,output,index+1,result);

//     // include
//     int element = nums[index];
//     output.push_back(element);
//     solve(nums,output,index+1,result);
// }

// vector<vector<int>> subsets(vector <int> nums) {
//     vector<vector<int>> result;
//     vector<int> output;
//     int index = 0;
//     solve(nums,output,index,result);
//     return result;
// }

// Using Bit
vector<vector<int>> subsets(vector <int> nums) {
    int n = nums.size();
    int mask_ct = (1<<n);
    vector<vector<int>> result;

    for(int mask = 0;mask<mask_ct;mask++) {
        vector<int> output;
        for(int i=0;i<n;i++) {
            if((mask & (1<<i)) != 0) {
                cout<<mask<<" "<<nums[i]<<" "<<i<<endl;
                output.push_back(nums[i]);
            }
        }
        result.push_back(output);
    }
    return result;
}


int main() {
    vector <int> nums = {1,2,3};
    vector<vector<int>> res = subsets(nums);

    for (auto list : res) {
        for(auto item : list) 
            cout<<item<<" ";
        cout<<endl;
    }
    return 0;
}