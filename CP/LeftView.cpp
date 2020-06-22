

class Solution {

int s=0 ;

int max ( int a , int b ) {
	return (a>b)? a:b ;
}

int height ( TreeNode* root ) 
{
	if (root==NULL)	return 0 ;
	return 1 + max ( height(root->left),height(root->right) ) ;
}

vector<TreeNode*> v ;
vector<TreeNode*> lv ;

void traverse ( TreeNode* root , int h ) {
	if (root==NULL)	return ;
	if (h==0)	
	{
		v.push_back(root) ;
	}
		traverse(root->left) ;
		traverse(root->right) ;
}

int fun ( TreeNode* root ) 
{
	int h = height(root) ;
	for ( int i=0 ; i<h ; i++ )
	{
		v.clear() ;
		traverse(root,h) ;
		lv.push_back(v[0]) ;
	}

	for ( TreeNode* t : lv ) {
		if (t->left==NULL&&t->right==NULL)			
			s += t->val ;
	}
return s ;
}

} ;