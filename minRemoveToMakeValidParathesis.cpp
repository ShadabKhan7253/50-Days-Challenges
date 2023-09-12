#include <iostream>
#include <string>
#include <stack>

using namespace std;

string minRemoveToMakeValid(string& s) {
    int n = s.size();
    stack <int> st;
    for(int i=0;i<n;i++) {
        if(s[i] == '(') 
            st.push(i);
        else if(s[i] == ')') {
            if(!st.empty())
                st.pop();
            else
                s[i] = '*';
        }
    }
    while(!st.empty()){
        s[st.top()] = '*';
        st.pop();
    }
    string res = "";
    for(int i = 0; i < s.size(); i++){
        if(s[i] != '*') {
            res += s[i];
        }
    }
    return res;
}

int main() {
    string str = "lee(t(c)o)de)";
    string res = minRemoveToMakeValid(str);
    cout<<res;
    return 0;
}