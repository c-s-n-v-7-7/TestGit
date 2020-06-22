#include<bits/stdc++.h>
using namespace std ;

struct Node {
	int val ;
	Node* next ;
} ;

int NoNodes ( Node* root )
{
	unordered_map<Node*,bool> vis ;
		int i=0 ;
		while(vis.find(root)==vis.end())
		{
			vis[root] = 1 ;
			root = root->next ;
		i++ ;
	}
return i ;
}

int main()
{
	int n ;
	cin >> n ;

	struct Node* root , temp ;
	root = (Node*)malloc(sizeof(Node*)) ;
		int v ;
		cin >> v ;
			root->val = v ;

	return 0 ;
}