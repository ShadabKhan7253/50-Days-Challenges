#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>

using namespace std;

// Time: O(n^2)
// Space: O(1)

// pair <int,int> twoNumberSum(vector <int> numbers, int target) {
//     for(int i=0;i<numbers.size();i++) {
//         int firstNumber = numbers[i];
//         for(int j=i+1;j<numbers.size();j++) {
//             int secondNumber = numbers[j];
//             int sum = firstNumber + secondNumber;
//             if(target == sum)
//                 return pair<int,int> {i,j};
//         }
//     }
//     return pair<int,int> {-1,-1};
// }

// Time: O(nlogn)
// Space: O(1)

// vector <int> twoNumberSumUsingSorting(vector <int> numbers,int target)
// {
//     vector <int> results;
//     int left,right;

//     sort(begin(numbers),end(numbers));

//     left = 0;
//     right = numbers.size() - 1;

//     while(left < right)
//     {
//         int testSum = numbers[left] + numbers[right];
//         if(testSum == target)
//         {
//             results.push_back(left);
//             results.push_back(right);
//             return results;
//         }
//         else if(testSum < target)
//         {
//             left++;
//         }
//         else
//             right--;
//     }

//     return results;
// }


// Time: O(2n) i.e O(n)
// Space: O(n)

// vector <int> twoNumberSumUsingHashTable(vector <int> numbers,int target)
// {
//     vector <int> results;
//     unordered_map <int,int> hash;

//     for(int i=0;i<numbers.size();i++)
//         hash.insert({numbers[i],i});
//     for(int i=0;i<numbers.size();i++) {
//         int currentNumber = numbers[i];
//         int secondNumber = target - currentNumber;

//         // search the second number
//         auto it = hash.find(secondNumber);
//         if(it!=hash.end())
//             return {i,it->second};
//     }
//     return results;
// }

// Time: O(n)
// Space: O(n)

vector <int> twoNumberSumUsingHashTable(vector <int> numbers,int target)
{
    vector <int> results;
    unordered_map <int,int> hash;

    for(int i=0;i<numbers.size();i++)
    {
        int currentNumber = numbers[i];
        int secondNumber = target - currentNumber;

        // search the second number
        if(hash.find(secondNumber) != hash.end())
        {
            results.push_back(hash[secondNumber]);
            results.push_back(i);
            return results;
        }
        // If not found then insert the current numbers is hash, so that it can be later search!
        hash[currentNumber] = i;
    }
    return results;
}


int main() {
    int n,a;
    vector <int> v = {1,5,6,3,4,9};
    int target = 8;
    // pair<int,int> p = twoNumberSum(v,target);
    // cout<<p.first<<" "<<p.second<<"\n";
    // vector<int> res = twoNumberSumUsingSorting(v,target);
    vector<int> res = twoNumberSumUsingHashTable(v,target);
    for(auto item: res)
        cout<<item<<" ";
    return 0;
}
