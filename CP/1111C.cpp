#include<bits/stdc++.h>
#define ll long long int
using namespace std ;

vector<ll> v ;

ll min ( ll a , ll b )
{
	return (a<b)? a:b ;
}

int n , k , a , b ;

ll Split ( int l , int r )
{
	auto it = v.lower_bound(r) ;
	auto it2 = v.lower_bound(l) ;
	if ( it2==v.end() )	Cost = a ;
	int cr=0 , cl=0 ;
	for ( int i=v.size()-1 ; i>=0 ; i-- )
	{
		if (v[i] <= r )	{cr=i ; break ;}
	}
	for ( int i=0 ; i<v.size()-1 ; i++ )
	{
		if (v[i] >= l )	{cl=i ; break ;}
	}
	int x = cr-cl ;
	ll C = n*
}

int main()
{
	cin >> n >> k >> a >> b ;
	ll l = pow(2,n) ;
	ll x ;
	for ( int i=0 ; i<k ; i++ )
	{
		cin >> x ;
		v.push_back(x) ;
	}
	sort(v.begin(),v.end()) ;
	
	ll Cost = b*l*k ;
	
	Cost = min ( Split(0,l/2) + Split(l/2+1,l) , Cost ) ;
	
	return 0 ;
}