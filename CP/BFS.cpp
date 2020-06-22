#include<bits/stdc++.h>
using namespace std ;

vector<unordered_set<int>> G ;
vector<bool> vis ;

void BFS ( queue<int>& q , vector<int>& v )
{
	if (q.size()==0)	return ;
	int y = q.front() ;
	q.pop() ;

	for ( int i : G[y] )
	{
		if(!vis[i])
		{
			vis[y] = 1 ;
			q.push(y) ;
			v.push_back(y) ; 
		}
	}
	BFS(q,v) ;
}

int main()
{
	int n ;
	int e ;
	cin >> n >> e ;
	int a , b ;

	G = vector<unordered_set<int>> (n) ;
	vis = vector<bool> (n,0) ;
	for ( int i=0 ; i<e ; i++ )
	{
		cin >> a >> b ;
			G[a].insert(b) ;
			G[b].insert(a) ;
	}

	// Assuming visit starts from 0th node 

	vis[0] = 1 ;

	vector<int> v ;
	queue<int> q ;
	q.push(0) ;
	v.push_back(0) ;
	BFS(q,v) ;

	return 0 ;
}