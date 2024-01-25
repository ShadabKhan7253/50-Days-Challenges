// Recursive Approach

class Solution {
public:
    int maxDepth(TreeNode* root) {
        if(root == NULL) {
            return 0;
        }
        return 1 + max(maxDepth(root->left),maxDepth(root->right));
    }
};

// Iterative Approach

class Solution {
public:
    int maxDepth(TreeNode* root) {
        if(root == NULL) {
            return 0;
        }
        vector <pair<int,TreeNode*>> my_stack;
        my_stack.push_back(pair<int,TreeNode*>(1,root));
        int max_depth = 0;

        while(!my_stack.empty()) {
            pair<int,TreeNode*> current_pair = my_stack.back();
            my_stack.pop_back();

            int current_depth = current_pair.first;
            TreeNode* current_node = current_pair.second;

            max_depth = max(max_depth,current_depth);
            if(current_node->left != NULL) {
                my_stack.push_back(pair<int,TreeNode*>(current_depth+1,current_node->left));
            } 
            if(current_node->right != NULL) {
                my_stack.push_back(pair<int,TreeNode*>(current_depth+1,current_node->right));
            }
        }
        return max_depth;
    }
};