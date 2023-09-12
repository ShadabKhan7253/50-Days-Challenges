#include <iostream> 
#include <vector> 
#include <algorithm> 

using namespace std;

vector<vector<int>> mergeInterval(vector<vector<int>> intervals) {

    sort(begin(intervals),end(intervals));
    vector<vector<int>> res;
    int start = intervals[0][0];
    int end = intervals[0][1];
    for(auto pair : intervals) {
        if(pair[0] <= end)
            end = max(end,pair[1]);
        else {
            res.push_back({start,end});
            start = pair[0];
            end = pair[1];
        }
    }
    res.push_back({start,end});
    return res;
}

int main() {
    vector<vector<int>> intervals = {
        {1,4},
        {0,4},
    };
    vector<vector<int>> res = mergeInterval(intervals);
    for(auto list : res) {
        for(auto item : list) {
            cout<<item<<" ";
        }
        cout<<endl;
    }
}