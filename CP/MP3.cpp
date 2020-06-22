#include<bits/stdc++.h>
#define ll long int
using namespace std ;

ll eval ( ll a )
{
	if (a==0)	return 0 ;
	return 1 + eval(a/2) ;
}

int main()
{
	int n ;
	ll I ;
	cin >> n >> I ;
	I *= 8 ; // Total memory.
	ll x ;
	unordered_map<ll,int> m ;
	for ( int i=0 ; i<n ; i++ )
	{
		cin >> x ;
		m[x]++ ;
	}
	multimap<int,ll> fre ;
	for ( auto it = m.begin() ; it !=m.end() ; ++it )
	{
		fre.insert(pair<int,ll>(it->second,it->first)) ;
	}
	int count = 0 ;
	ll k = eval (I/n) ;
	while (k<fre.size())
	{
		 count += fre.begin()->first ;
		 fre.erase(fre.begin()) ;
	}  
	cout << count ;
	return 0 ;
}