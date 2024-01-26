// Recursive Approach

class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if(root == NULL || root == p || root == q)
            return root;

        TreeNode *left = lowestCommonAncestor(root->left,p,q);
        TreeNode *right = lowestCommonAncestor(root->right,p,q);

        return left ? (right ? root : left) : right;
    }
};

// Iterative Appraoch

class Solution {
public:
    TreeNode* answer = NULL;
    
    bool recursiveTree(TreeNode* currentNode, TreeNode* p, TreeNode* q) {
        if(currentNode == NULL) 
            return false;

        int left = recursiveTree(currentNode->left,p,q) ? 1 : 0;
        int right = recursiveTree(currentNode->right,p,q) ? 1 : 0;
        int mid = (currentNode == p || currentNode == q) ? 1 : 0;
        if(left + right + mid >= 2)
            answer = currentNode;
        return (left + right + mid) > 0;
    }

    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        recursiveTree(root,p,q); 
        return answer; 
    }
};