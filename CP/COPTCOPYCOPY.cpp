#include<bits/stdc++.h>
#define ll long int
using namespace std ;

int main()
{
	unordered_set<ll> s ;
	int t ;
	cin >> t ;
	while(t--)
	{
	int n ;
	cin >>  n ;
	ll c ;
	for ( int o=0 ; o < n ; o++ )
	{
		cin >> c ;
		s.insert(c) ;
	}
	cout << s.size() << "\n" ;
	s.clear() ;
	}
	return 0 ;
}