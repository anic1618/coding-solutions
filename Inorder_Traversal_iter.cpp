

Given a binary tree, return the inorder traversal of its nodes’ values.

Example :
Given binary tree

   1
    \
     2
    /
   3

return [1,3,2].

Using recursion is not allowed.



/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
vector<int> Solution::inorderTraversal(TreeNode* A) {
  vector<int> ans;
  if(A == NULL) return ans;
 
  TreeNode* curr =NULL,*pre =NULL;
  curr = A;
  stack<TreeNode*> stk;
  while(curr != NULL) {
           stk.push(curr);
           curr=curr->left;
  }
  while(!stk.empty()){
       curr = stk.top();stk.pop();
       ans.push_back(curr->val);
       curr=curr->right;
    while(curr != NULL) {
           stk.push(curr);
           curr=curr->left;
    }    
  }
   return ans;
}
