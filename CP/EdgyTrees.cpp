#include<bits/stdc++.h>
#define p 1000000007
using namespace std ;

unordered_map<int,bool> tree[n] ;
vector<bool> visited ;
vector<int> dp ;

unordered_set<unordered_set<int>> ums ; 

int count = 0 ;

void dfs ( int i , unordered_set<int> g )
{
	visited[i] = 1 ;
	bool f=0 ;
	for ( auto j=tree[i].begin() ; j!=tree[i].end() ; ++j )
	{
		if ( visited[j->first])	continue ;
		if (j->second==0)
		  {
		  	f=1 ;
		  	g.insert(j->first) ;
		  	dfs (j->first,g) ;
		  }
		 else
		 {
		 	unordered_set<int> l ;
		 	l.insert(j->first) ;
		 	dfs (j->second,l) ;
		 }
	}
	if(!f)	ums.insert(g) ;
}

int main()
{
int n , k ;
cin >> n >> k ;

int x , y ;
bool c ;

visited = vector<bool> (n,0) ; 
vector<int> dp
	for ( int i=0 ; i<n-1 ; i++ )
			{
				cin >> x >> y >> c ;
				tree[x].insert(pair<int,bool>(y,c) ) ;
				tree[y].insert(pair<int,bool>(x,c)) ;
			}

for ( auto u = ums.begin() ; u !=ums.end(); )
{
	if(u.size()==1||u.empty())	ums.erase(u) ;
	else	++u ;
}

int total = (n*(n-1))/2 ;
cout << total - count ;
	return 0 ;
}