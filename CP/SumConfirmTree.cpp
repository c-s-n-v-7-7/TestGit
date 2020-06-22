unordered_map<pair<Node*,int>,bool> dp ;

bool Sum ( int v , Node* root ) 
{
	if (v==0)	return 1 ;
	if (root==NULL)	return 0 ;

	bool f=0 ;

	pair<Node*,int> p ;
	p.first = root ;
	p.second = v ;

	if (dp.find(p)==dp.end())
	{
	f |= Sum(v-root->val,root->left)||Sum(v-root->val,root->right)||Sum(v,root->left)||Sum(v,root->right) ;
		dp[p] = f ;
	}
	return dp[p] ;
}