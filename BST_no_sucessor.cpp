/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
TreeNode* Solution::getSuccessor(TreeNode* A, int B) {
    TreeNode* root = A,*par=NULL,*nextB=NULL;
    while(root != NULL){
        par = root;
        if(root->val>B) {
            nextB =root;
            root=root->left;
        }
        else {
            
            root=root->right;
        }
    }
    
    //null BST || closest node to B
    if( !par || par->val != B) return par;
    else {
        return nextB;
    }
}

TreeNode* Solution::getSuccessor(TreeNode* A, int B) {
    TreeNode* root = A,*succ=NULL;
    while(root != NULL){
        if(root->val>B) {
            succ =root;
            root=root->left;
        }
        else if(root->val<B){
            
            root=root->right;
        }
        else break;
    }
    
    if(root != NULL && (root = root->right) !=NULL){ 
        while(root->left !=NULL) root=root->left;
            return root;
    }
    return succ;
}
