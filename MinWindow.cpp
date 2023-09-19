#include <iostream>
#include <vector>

using namespace std;

 string minWindow(string s, string t) {
    vector<int> v(128,0);
    for (char c : t)
        v[c]++;
    int n = s.size();
    int counter = t.size(), i = 0, j = 0, d = INT_MAX, head = 0;
    while (j < n){
        if (v[s[j++]]-- > 0) 
            counter--;
        while (counter == 0) {
            if (j - i < d) {
                head = i;
                d = j - head;
            }
            if (v[s[i++]]++ == 0)
                counter++;
        }  
    }
    return d == INT_MAX ? "" : s.substr(head, d);
}

int main() {
    string s = "abc";
    string t = "b";
    string res = minWindow(s,t);
    cout<<res<<endl;
    return 0;
}