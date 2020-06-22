#include<bits/stdc++.h>
#define ll long int

using namespace std ;

int main()
{
	int n ;
	cin >> n ;
	set<ll> s ;
	mulitiset<ll> s1;
	ll c ;
	for ( int o=0 ; o<n ; o++ )
	{
		cin >> c ;
		if(s.find(c)!=s.end())	{s1.insert(c); continue ;}
		s.insert(c) ;
	}
	set<ll>::iterator j ;
	mulitiset<ll>::iterator k ;
	int c=0 ;
	while(c<=n/2)
	{
		for ( j=s.begin() ; j!=s.end() ; )
		{
			cout << *j << " " ;
			c++ ;
			s.erase(j) ;
			if(c>n/2)	break ;
		}
		if(c>n/2)	break ;
		for ( k=s1.begin() ; k!=s1.end(); )
		{
			cout << *k << " " ;
			c++ ;
			s1.erase(k) ;
			if(c>n/2)	break ;
		}
	}
	for (auto rit = s.rbegin() ; rit!=s.rbegin() ; ++rit)
	{
		cout << *rit << " " ;
	}
	for ( auto rit = s1.rbegin() ; rit!=s.rbegin() ; ++rit)
	{
		cout << *rit < " " ;
	}
	return 0 ;
}