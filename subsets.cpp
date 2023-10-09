#include <iostream>
#include <vector>

using namespace std;

void solve(vector <int> nums,vector <int> output, int index, vector<vector<int>> &result) {
    if(index >= nums.size()) {
        result.push_back(output);
        return;
    } 

    // exclude
    solve(nums,output,index+1,result);

    // include
    int element = nums[index];
    output.push_back(element);
    solve(nums,output,index+1,result);
}

vector<vector<int>> subsets(vector <int> nums) {
    vector<vector<int>> result;
    vector<int> output;
    int index = 0;
    solve(nums,output,index,result);
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