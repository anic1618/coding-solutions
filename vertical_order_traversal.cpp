//Vertical Order traversal of Binary Tree  
Given a binary tree, print a vertical order traversal of it.

Example :
Given binary tree:

      6
    /   \
   3     7
  / \     \
 2   5     9

returns

[
    [2],
    [3],
    [6 5],
    [7],
    [9]
]


/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
  int mmax,mmin;
void getPos(TreeNode* A,int pos){
    if (!A) return;
    getPos(A->left,pos-1);
    getPos(A->right,pos+1);
    if(pos < mmin) mmin = pos;
    else if(pos > mmax)  mmax = pos;
    
}
vector<vector<int> > Solution::verticalOrderTraversal(TreeNode* A) {
   // 
     if(!A) return vector<vector<int> >();
   
    queue<pair<TreeNode*,int>> Q;//node,pos

    mmax = 0;
    mmin = 0;
    getPos(A,0);
    //cout<<mmax<<" "<<mmin<<"\n";
    vector<vector<int> > ans(mmax-mmin+1,vector<int>() );
   
    Q.push(make_pair(A,0-mmin));//val,pos
    pair<TreeNode*,int> temP;
    TreeNode* temN;
    int pos;
    while(!Q.empty()){
        temP = Q.front();Q.pop();
        pos = temP.second;
        temN = temP.first;
        assert(0<=pos && (mmax-mmin+1) > pos);
        ans[pos].push_back(temN->val);
        if(temN->left != NULL) Q.push(make_pair(temN->left,pos-1));
        if(temN->right != NULL) Q.push(make_pair(temN->right,pos+1));
    }
    
    return ans; 
}
