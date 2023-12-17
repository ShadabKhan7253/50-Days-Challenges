#include <iostream>
#include <vector>
#include <stack>

using namespace std;

vector<int> preSamaller(vector<int>& heights) {
    vector <int> ps;
    stack <int> s;
    for(int i=0;i<heights.size();i++) {
        while(!s.empty() && heights[s.top()] >= heights[i])
            s.pop();
        if(s.empty())
            ps.push_back(-1);
        else
            ps.push_back(s.top());
        s.push(i);
    }
    return ps;
}
vector<int> nextSamaller(vector<int>& heights) {
    int n = heights.size();
    vector <int> ns(n,n);
    stack <int> s;
    n = n-1;
    for(int i=n;i>=0;i--) {
        while(!s.empty() && heights[s.top()] >= heights[i]) {
            s.pop();
        }
        if(s.empty())
            ns[n--] = heights.size();
        else
            ns[n--] = s.top();
        s.push(i);
    }
    return ns;
}
int largestRectangleArea(vector<int>& heights) {
    vector <int> ps = preSamaller(heights);
    vector <int> ns = nextSamaller(heights);

    int currentLength = 0;
    int maxLength = 0;
    for(int i=0;i<heights.size();i++) {
        currentLength = (ns[i] - ps[i] - 1) * heights[i];
        maxLength = max(maxLength,currentLength);
    }
    return maxLength;
}

int main() {
    vector<int> heights = {2,1,5,6,2,3};
    int res = largestRectangleArea(heights);
    cout<<res;
    return 0;
}
