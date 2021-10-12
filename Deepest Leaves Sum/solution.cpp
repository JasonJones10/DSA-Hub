class Solution {
public:
    
    void len(TreeNode* head, int &curr, int d)
    {
        curr = max(curr, d);
        
        if(head->left!=NULL)
        {
            len(head->left, curr, d+1);
        }
        
        if(head->right!=NULL)
        {
            len(head->right, curr, d+1);
        }
        
        return;
        
    }
    
    void dfs(TreeNode* head, int sum, int &ans, int &curr, int d)
    {
        
        if(curr==d)
        {
            ans = ans + head->val;
        }
        
        if(head->left!=NULL)
        {
            dfs(head->left, sum, ans, curr, d+1);
        }
        
        if(head->right!=NULL)
        {
            dfs(head->right, sum, ans, curr, d+1);
        }
        
        return;
        
    }
    
    
    int deepestLeavesSum(TreeNode* root) {
        
        int ans = 0;
        int curr = 0;
        
        len(root, curr, 0);
        
        dfs(root, 0, ans, curr, 0);
        
        return ans;
        
        
    }
};
