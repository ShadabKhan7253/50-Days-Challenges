// Recursive Approach

class Solution {
public:
    bool isSubtree(TreeNode* root, TreeNode* subRoot) {
        return preorder(root,subRoot);
    }

    bool preorder(TreeNode *s,TreeNode *t) {
        if (t == NULL)
            return true;
        if (s == NULL)
            return false;
        return (isSameTree(s,t)) || preorder(s->left,t) || preorder(s->right,t);
    }

    bool isSameTree(TreeNode* p,TreeNode* q) {
        if(p == NULL && !q)
            return true;
        if(!p || !q) 
            return false;

        return p->val == q->val && isSameTree(p->left,q->left) && isSameTree(p->right,q->right);
    }
};

// Iterative Approach

class Solution {
public:

    bool isSameTree(TreeNode* root,TreeNode* subRoot) {
        stack <TreeNode*> s1,s2;
        s1.push(root);
        s2.push(subRoot);

        while(!s1.empty() && !s2.empty()) {
            TreeNode* node1 = s1.top();
            TreeNode* node2 = s2.top();

            s1.pop();
            s2.pop();

            if(!node1 && !node2) 
                continue;
            
            if(node1 && !node2 || !node1 && node2) 
                return false;

            if(node1->val != node2->val)
                return false;

            s1.push(node1->right);
            s2.push(node2->right);
    
            s1.push(node1->left);
            s2.push(node2->left); 
        }

        if (s1.empty() && s2.empty())
            return true;
        else
            return false;
    }

    bool isSubtree(TreeNode* root, TreeNode* subRoot) {
        stack <TreeNode*> s;
        s.push(root);
        while(!s.empty()) {
            TreeNode* node = s.top();
            s.pop();

            if(node->val == subRoot->val) {
                if(isSameTree(node,subRoot))
                    return true;
            }

            if(node->right)
                s.push(node->right);
                
            if(node->left)
                s.push(node->left);      
        }
        return false;
    }
};