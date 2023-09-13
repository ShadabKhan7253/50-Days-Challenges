#include <iostream>
#include <unordered_map>
#include <queue>

using namespace std;

bool permutationString(string s1,string s2) {
    int size1 = s1.size();
    int size2 = s2.size();

    if(size1 > size2) 
        return false;

    vector <int> l1(26,0);
    vector <int> l2(26,0);

    int left = 0, right = 0;
    while(right < size1) {
        l1[s1[right] - 'a'] += 1;
        l2[s2[right] - 'a'] += 1;
        right++;
    }
    right -= 1;

    while(right < size2) {
        if(l1 == l2) {
            return true;
        }
        right +=1;
        if(right != size2) 
            l2[s2[right] - 'a'] += 1;
        l2[s2[left] - 'a'] -= 1;
        left++;
    }
    return false;
}

int main() {
    string s1 = "ab";
    string s2 = "eidbaooo";
    cout<<boolalpha;
    bool res = permutationString(s1,s2);
    cout<<res;
    return 0;
}