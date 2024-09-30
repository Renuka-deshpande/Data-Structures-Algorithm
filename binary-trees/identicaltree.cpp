class solution{
 bool issametree(treenode*p,treenode*q){
        if(p==NULL || q==NULL){
            return(p==q);
        }
        return (p->data==q->data)
        && issametree(p->left,q->left)
        && issametree(p->right,q->right);
  }  
};
//TC O(N) SC O(N)
