/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
vector<int> Solution::postorderTraversal(TreeNode* A) {
    vector<int> ans;
    if(A == NULL) return ans;
    TreeNode* cur = A,*tem;
    
    stack<TreeNode*> stk;
    if(cur!= NULL){
            if(cur->right != NULL) stk.push(cur->right);
            stk.push(cur);
            cur=cur->left;
    }
    
    while(!stk.empty()){
        if(cur!= NULL){
            if(cur->right != NULL) stk.push(cur->right);
            stk.push(cur);
            cur=cur->left;
        }
        else {
            cur = stk.top();stk.pop();
            if(cur->right != NULL && !stk.empty() && cur->right == stk.top()){
                tem = stk.top();stk.pop();
                stk.push(cur);
                cur = tem;
            }
            else {
                ans.push_back(cur->val);
                cur = NULL;
            }
        }  
    }
    
    return ans;
}
