// Naive Approach
// Time : O(n) + O(nlogn)
// Space : O(n)

class Solution {
public:
    void preOrderTraversal(TreeNode* root, vector<int> &v){
        if(root == NULL)    return;
    
        v.push_back(root->val);
        preOrderTraversal(root->left, v);
        preOrderTraversal(root->right, v);      
    }
    int kthSmallest(TreeNode* root, int k) {
        vector<int> v; 
        preOrderTraversal(root, v);
        sort(v.begin(), v.end());
        return v[k-1];
    }
};

// Time : O(n)
// Space : O(n)

class Solution {
public:
    void inOrderTraversal(TreeNode* root, vector<int> &v){
        if(root == NULL)    return;
    
        inOrderTraversal(root->left, v);
        v.push_back(root->val);
        inOrderTraversal(root->right, v);      
    }
    int kthSmallest(TreeNode* root, int k) {
        vector<int> v; 
        inOrderTraversal(root, v);
        return v[k-1];
    }
};

// Optimized
// Time : O(n)
// Space : O(1)

class Solution {
public:
    int count = 0;
    void inOrderTraversal(TreeNode* root, int &k, int &count, int &ans){
        if(root == NULL) return;
    
        inOrderTraversal(root->left, k, count, ans);
        count++;
        if(count == k) {
            ans = root->val;
            return;
        }
        inOrderTraversal(root->right,k, count, ans );      
    }
    int kthSmallest(TreeNode* root, int k) {
        int count = 0,ans=0;
        inOrderTraversal(root, k, count, ans);
        return ans;
    }
};





