#include<bits/stdc++.h>
using namespace std ;

vector<unordered_multiset<int>> b ;
vector<bool> vis ;
multimap<int,int> m ;
multimap<int,int> stedge ;
vector<int> a ;
vector<int> c ;

void Tree( int x )
{
	auto it = m.find(x);
	vis[x] = 1 ;
	for ( auto j=it ; j!=m.end() ; ++j )
	{
		if(!vis[j->second])
		{
			stedge.insert(pair<int,int>(j->first,j->second)) ;
			Tree(j->second) ;
		}
	}
}

unordered_set<int> B ( int x )
{
	if (b[x].empty())
	{
		unordered_set<int> u ;
		vis[x] =  1 ;
		auto it = m.find(x) ;
		u.insert(c[x]) ;
		unordered_set<int> kl ;
		for ( auto j=it ; j!=m.end() ; ++j )
		{
			if(j->first!=it->first)	break ;
			
			if(!vis[j->second])
			{
				kl = B(j->second) ;
				u.insert(kl.begin(),kl.end()) ;
				kl.clear() ;
			}
		}
		b[x].insert(u.begin(),u.end()) ;
		vis[x] = 0 ;
	}
return b[x] ;
}

int main()
{
	int t ;
	cin >> t ;
		while(t--)
		{
			int n , q ;
			cin >> n >> q ;
			int x , y ;
			for ( int i=0 ; i<n-1 ; i++ )
			{
				cin >> x >> y ;
				m.insert(pair<int,int>(x,y)) ;
				m.insert(pair<int,int>(y,x)) ;				
			}
			
			Tree(1) ;
			
			a = vector<int> (n+1); 
			c = vector<int> (n+1);
			for ( int i=1 ; i<=n ; i++ )	cin >> c[i] ;
			for ( int i=1 ; i<=n ; i++ )	cin >> a[i] ;
		
		unordered_set<int> u ;
		u.clear() ;
			
			b = vector<unordered_set<int>> (n+1,u) ;
			vis = vector<bool> (n+1,0) ;

			for ( int i=1 ; i<=n ; i++ )
			{
				if (b[i].empty())	b[i] = B(i) ;
			}
		while(q--)
		{
			int i , val ;
			cin >> i >> val ;
			stedge[i] = val ;
		
			b[i].erase(b[i].find(c[i])) ;
			b[i].insert(val) ;
		}
		
		}
	return 0 ;
}