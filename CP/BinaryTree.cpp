#include<bits/stdc++.h>
using namespace std ;

class Node {
	int val ;
	Node* left ;
	Node* right ;
		public :
			Node (int n)
			{
				val = n ;
				left = NULL ;
				right = NULL ;
			}
			Node* insert( Node* root , int val )
			{
				if (root==NULL)	
				{
					Node n = Node(val) ;
					root = (Node*)malloc(sizeof(Node*)) ;
					root = &n ;
				}
				if (root->val<val)	
				{
					root->right = insert(root->right,val) ;
				}
				if (root->left>val)
				{
					root->left = insert(root->left,val) ;
				}
				return root ;
			}

} *base ;

int main()
{
	int n ;

	cin >> n ;

	int v ;
	for ( int i=0 ; i<n ; i++ )
	{
		cin >> v ;
			base = insert(base,v) ;
	}
	
	return 0 ;
}