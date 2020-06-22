#include<bits/stdc++.h>
#include<utility>
using namespace std ;

map<pair<int,int>,int> wt ;
unordered_set<int> visited ; 
unordered_multimap<int,int> tree ;
set<int> poss ;
bool f=0 ;
void MST( int x )
{
	visited.insert(x) ;
	unordered_multimap<int,int>::iterator it ;
	it = tree.find(x); 
	for (auto j=it ; j!=tree.end() , j->first==x ; j++ )
	{
		pair<int,int> p ;
		p.first = x ;
		p.second = it->second ;
		int temp ;
		if(f)	{ temp = *poss.begin() ; poss.erase(poss.begin()) ; }
		if(!f)	{ temp = *poss.rbegin() ; poss.erase(poss.find(*poss.rbegin())) ; }
		f=!f ;
		wt.insert(pair<pair<int,int>,int>(p,temp)) ;
		visited.insert(it->second) ;
	}
	visited.erase(visited.begin()) ;
	if(visited.empty())	return ;
	MST(*visited.begin()) ;
}

int main()
{
	int n ;
	cin >> n ; 
	for ( int i=0 ; i<n-1 ; i++ )	poss.insert(i) ;
		int x , y ;
		n-- ;
		while(n--)
		{
			cin >> x >> y ;
			tree.insert(pair<int,int>(x,y)) ;
		}
	 MST(1) ;
	 for ( auto it = tree.begin() ; it!=tree.end() ; ++it )
	 {
	 	cout << wt[*it] << "\n" ;
	 }
	return 0 ;
}