class Solution {
public:
    long long sum = 0;
    void dfs(TreeNode* root, long long val) {
        if(!root)
            return; 
        val *= 10;
        val += root->val;
        if(!root->left && !root->right) {
            sum += val;
            return;
        }
        dfs(root->left,val);
        dfs(root->right,val); 
    }
    int sumNumbers(TreeNode* root) {
        dfs(root,0);
        return sum;
    }
};


***************************************

class Solution {
public:
    int sumNumbers(TreeNode* root,string number = "") {
        if (!root)
            return 0;

        number += to_string(root->val);

        if (!root->left && !root->right)
            return stoi(number);
            
        int result1 = sumNumbers(root->left, number);
        int result2 = sumNumbers(root->right, number);

        return result1 + result2;
    }
};