#include <iostream>
#include <vector>

using namespace std;

vector<string> valid;
void generate(string &s, int open, int close) {
    if(open == 0 && close == 0) {
        valid.push_back(s);
        return;
    }

    if(open > 0) {
        s.push_back('(');
        generate(s,open-1,close);
        s.pop_back();
    }

    if(close > 0 && open < close) {
        s.push_back(')');
        generate(s,open,close-1);
        s.pop_back();
    }  
}

vector<string> generateParenthesis(int n) {
    string s;
    generate(s,n,n);
    return valid;
}

int main() {
    int n = 3;
    vector<string> res = generateParenthesis(n);
    for(string str : res) {
        cout<<str<<endl;
    }
    return 0;
}