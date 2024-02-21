class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map <string, vector<string>> groups;

        for(const auto& str: strs) {
            string temp {str};
            sort(begin(temp),end(temp));
            groups[temp].push_back(str);
        }

        vector <vector<string>> anagrams;
        for(auto i : groups)
        {
            anagrams.push_back(i.second);
        }
        return anagrams;
    }
};


// optimal approach 

class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        map<map<char,int>,vector<string>> hashmap;

        
        for(auto str : strs) {
            map<char, int> freq;
            for(auto c : str) {
                freq[c]++;
            }
            if(hashmap.find(freq) != hashmap.end()) {
                hashmap[freq].push_back(str);
            } else{
                vector<string> tempStr;
                tempStr.push_back(str);
                hashmap[freq] = tempStr;
                // hashmap.insert({freq, tempStr});
            }
        }
        vector<vector<string>> anagrams;
        for (auto p : hashmap) { 
            anagrams.push_back(p.second);
        }
        return anagrams;
    }
};

// Using Trie

class TrieNode
{
    public:
    TrieNode* links[26];
    bool end = false;
    vector<int> idx;
};

class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        TrieNode* root = new TrieNode();

        for(int i = 0; i < strs.size(); ++i)
        {
            string str = strs[i];
            sort(begin(str),end(str));
            TrieNode* curr = root;
            for(char c : str)
            {
                if(!curr->links[c - 'a'])
                curr->links[c - 'a'] = new TrieNode();
                curr = curr->links[c - 'a'];
            }
            curr->end = true;
            curr->idx.push_back(i);
        }

        vector<vector<string>> res;

        for(int i = 0; i < strs.size(); ++i)
        {
            string str = strs[i];
            sort(begin(str),end(str));
            TrieNode* curr = root;

            for(char c : str)
            {
                if(!curr->links[c - 'a']){
                    break;
                }
                curr = curr->links[c - 'a'];
            }

            if(curr->end)
            {
                vector<int> indexes(curr->idx);
                vector<string> row;
                for(int ind : indexes)
                {
                    row.push_back(strs[ind]);
                }
                res.push_back(row);
                curr->end = false;
            }
        }

        return res;
    }
};