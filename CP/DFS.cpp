#include<bits/stdc++.h>
using namespace std ;

vector<unordered_set<int>> G ;
vector<bool> vis ;

void DFS( int i )
{
	cout << i << " " ;
	
	for ( int j : G[i] )
	{
		if(!vis[j])
		{
			vis[j] = 1 ;
			DFS(j) ;
		}
	}
}

int main()
{
	int n , e ;
	cin >> n >> e ;

	vis = vector<bool> (n,0) ;
		
	G = vector<unordered_set<int>> (n) ;

	int a , b ;

	for ( int i=0 ; i<e ; i++ )
	{
		cin >> a >> b ;
		G[a].insert(b) ;
		G[b].insert(a) ;
	}

	// Assuming 0th node is starting node 
	vis[0] = 1 ;

	DFS(0) ;

	return 0 ;
}