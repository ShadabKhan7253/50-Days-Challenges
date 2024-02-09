class Solution {
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> res;
        if(root == NULL) return res;
        queue <TreeNode*> q;
        q.push(root);

        while(!q.empty()) {
            int size = q.size();
            vector <int> temp;
            for(int i=0;i<size;i++) {
                TreeNode* node = q.front();
                q.pop();
                if(node->left) q.push(node->left);
                if(node->right) q.push(node->right);
                temp.push_back(node->val);
            }
            res.push_back(temp);
        }
        return res;
    }
};