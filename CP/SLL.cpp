#include<bits/stdc++.h>
using namespace std ;

struct Node
{
	int val ;
	Node* next ;

} *root ;

int main()
{
	int n ;
	cin >> n ;

	root = NULL ;

	root = (Node*) malloc(sizeof(Node*)) ;

	int v ;
	cin >> v ;

	 root->val = v ;
	 root->next = NULL ;

	Node* temp = root ;

		n-- ;

		while(n--)
		{
			cin >> v ;
			temp = temp->next ;
			Node* d = temp ;
				d = (Node*)malloc(sizeof(Node*)) ; 
				cin >> v ;
				d->val = v ;
				d->next = NULL ;
					temp = d ;
		} 

		Node * t = root ;
			while(t!=NULL)
			{
				cout << t->val << " " ;
					t = t->next ;
			}

	return 0 ;
}