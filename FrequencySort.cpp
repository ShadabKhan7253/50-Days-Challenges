#include <iostream>
#include <unordered_map>
#include <queue>

using namespace std;

string frequencySort(string s) {
    unordered_map <char,int> map;
    for(int i=0;i<s.size();i++)
        map[s[i]]++;
    priority_queue<pair<int,char>> pq;
    for(auto it : map)
        pq.push({it.second,it.first});

    string ans = "";
    while(!pq.empty()) {
        auto i = pq.top();
        int occ = i.first;
        char ch = i.second;
        pq.pop();
        ans.append(occ, ch);
    }
    return ans;
}

int main() {
    string s = "abtsssTTasbttt";
    string res = frequencySort(s);
    cout<<res;
    return 0;
}