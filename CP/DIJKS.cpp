#include<bits/stdc++.h>
using namespace std ;

vector<unordered_set<pair<int,int>>> G ;
vector<bool> vis ;
priority_queue<pair<int,int>> q ;

int main()
{
	int n , e ;
	cin >> n >> e ;

		G = vector<unordered_set<pair<int,int>>> (n) ;

		vis = vector<bool> (n,0) ;

		int a , b , c ;

		for ( int i=0 ; i<e ; i++ )
		{
			cin >> a >> b >> c ;
			G[a].insert(pair<int,int>(b,c)) ;
			G[b].insert(pair<int,int>(a,c)) ;
		}

	// Starting from node 0 
		int dest ;
		cin >> dest ;
			int cost = -1 ;
		q.push(pair<int,int>(0,0)) ;

		while(!q.empty())
		{
			
			int d = q.front().first ;
			int s = q.front().second ;
						q.pop() ;
					if (s==dest)	
					{
						cost = d ;
						break ;
					}
				if (vis[s])	continue ;
				vis[s] = 1 ;
			for ( pair<int,int>p : G[s] )
			{
				if (!vis[p.first])
				{
					q.push(pair<int,int>(d+p.second,p.first)) ;
				}
			}
 		}
 		cout << cost ;
	return 0 ;
}