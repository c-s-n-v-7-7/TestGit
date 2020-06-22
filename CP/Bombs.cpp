//Incomplete 1326E
#include<bits/stdc++.h>
#define ll long int
using namespace std ;

int main()
{
	ll n ;
	cin >> n ;
	
	ll p[n+1] ;
	ll q[n] ;
	set<ll> a ;
	
	p[0] = 0 ;
	for ( ll i=1 ; i<=n ; i++ )	
	 cin >> p[i] ; 

	ll f ;
	map<ll,ll> indwise ;
	unordered_map<ll,ll> qnt ;
	for ( ll i=0 ; i<n ; i++ )
	{
		cin >> q[i] ;
		indwise.insert(pair<ll,ll>(q[i],i)) ;		
	}

	map<ll,ll>::iterator j ;

	for ( auto it = indwise.begin() ; it!=indwise.end() ; ++it )
	{
			j=indwise.find(*it) ;
			int c=0 ;
			for ( auto itr = indwise.begin() ; it!j ; ++it )
			{
				if(itr->second<j->second)	c++ ;
			}
		c++ ;
		qnt.insert(pair<ll,ll>(it->second,c)) ;
	}
	
	cout << *a.rbegin() << " " ;
	int last=0 ;
	for ( ll i=1 ; i<n ; i++ )	
	{
		a.insert(p[i]) ;
		while(last<i&&q[last]<p[])
	}

	return 0 ;
}