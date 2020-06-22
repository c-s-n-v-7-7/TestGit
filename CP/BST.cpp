#include<bits/stdc++.h>
using namespace std ;

class node {
	public : 
	int val ;
	node* next ;
	node( int v ) 
	{
		val = v ;
		next = NULL ;
	}
	void insert ( node* root , int v )
	{
		if (root==NULL)	
		{
			root = (node*)malloc(sizeof(node*)) ;
			root = node(v) ;
		}
		if (root->val>v)
		{
			insert(root->left,v) ;
		}
		if (root->val<v) 
		{
			insert(root->right,v) ;
		}
	}
	bool search ( node* root , int v )
	{
		if (root==NULL)	return 0 ;
		if (root->val>v)	return search(root->left,v) ;
		if (root->val<v)	return search(root->right,v) ;
		if (root->val==v)	return 1 ;
	}
} *base ;

int main()
{
	int n ;
	cin >> n ;
	node *temp ;
	int y ;
	cin >> y ;
		temp = 
		for ( int i=0 ; i<n-1 ; i++ )
		{
			int g ;
			cin >> g ;

		}
	return 0 ;
}