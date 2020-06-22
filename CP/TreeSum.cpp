

class Solution {

int n = 0 ;

unordered_map<TreeNode*,bool> dp ;

int o ;

bool Add ( TreeNode* root , int s ) {
	if ( s==0 )	{ return 1 ; n++ ; }
 	if (root==NULL)	return 0 ;
		if ( dp.find(root)!=dp.end())
		{
			bool f=0 ;
			f |= Add(root->left,s-root->val)||Add(root->right,s-root->val)||Add(root->left,o)||Add(root->right,o) ;
			dp.insert(pair<TreeNode*,bool>(root,f)) ;
		}
	return dp[root] ;
}

int Sum ( TreeNode* root , int s ) {
	 o = s ;
	 Add(root,s) ;
	 return n ;
}

} ;