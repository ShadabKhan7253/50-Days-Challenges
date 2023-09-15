#include <iostream>
#include <vector>

using namespace std;

class Solution {

public: 
    vector<vector<string>> partition(string s) {
        vector<vector<string>> res;
        vector<string> substr;
        func(0,s,substr,res);
        return res;
    }

    void func(int index,string s,vector<string> &substr, vector<vector<string>> &res) {
        if(index == s.size()) {
            res.push_back(substr);
            return;
        }
        for(int i = index; i<s.size();++i) {
            if(isPalindrome(s,index,i)) {
                substr.push_back(s.substr(index,i - index+1));
                func(i+1,s,substr,res);
                substr.pop_back();
            }
        }
    }

    bool isPalindrome(string s,int start, int end) {
        while(start <= end) {
            if(s[start++] != s[end--])
                return false;
        }
        return true;
    }
};



int main() {
    string str = "aabb";
    Solution s;
    vector<vector<string>> res = s.partition(str);
    for(auto list : res) {
        for(auto item : list) {
            cout<<item<<" ";
        }
        cout<<endl;
    }
    return 0;
}