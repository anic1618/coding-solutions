flatten binary tree;

TreeNode* head = NULL;
 pair<TreeNode*,TreeNode*> fun(TreeNode* A){
     if(A == 0) return make_pair((TreeNode*)NULL,(TreeNode*)NULL);
     pair<TreeNode*,TreeNode*> lmst = fun(A->left);
     pair<TreeNode*,TreeNode*> rmst = fun(A->right);
     if(lmst.second) lmst.second->right = A;
     if(rmst.first) A->right = rmst.first;
     if(!head) head = lmst.first?lmst.first:A;
     if(lmst.first == NULL) lmst.first = A;
     if(rmst.second == NULL) rmst.second = A;
     return make_pair(lmst.first,rmst.second);
 }
 
TreeNode* Solution::flatten(TreeNode* A) {
    if(A ==  NULL) return A;
    fun(A);
    return head;
    
}
