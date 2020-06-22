#include<bits/stdc++.h>
using namespace std; 

vector<bool> vis ;
vector<unordered_set<pair<int,int>>> G ;

priority_queue<pair<int,pair<int,int>>> pq ; 

vector<int> v ;

int main()
{
	int n , e ;
	cin >> n >> e ;

	for ( int i=0 ; i<e ; i++ )
	{
		int a , b , c ;
		cin >> a >> b >> c ;
		pair<int,int> p ;
		p.first = a ;
		p.second = b ;
			pq.push(pair<int,pair<int,int>>(c,p)) ;
	}


	while(!pq.empty())
	{
		int x = pq.front().second.first ;
		int y = pq.front().second.second ;

		pq.pop() ;
			
			if (vis[x]&&vis[y])	
				continue ;
		vis[x] = 1 ;
		vis[y] = 1 ;
		
		v.push(x) ;  
		v.push(y) ;
	}

	for ( int i : v ) 
		cout << i << " " ;
	
	return 0 ;
}