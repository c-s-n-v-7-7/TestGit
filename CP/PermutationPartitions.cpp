// n+k-1 C n - the no. of ways the 3 top no.s can be in same set
#include<bits/stdc++.h>
#define p 998244353 
#define ll long long int 
using namespace std ;

int main()
{
	ll n , k ;
	cin >> n >> k ;
	ll a[n] ;
	ll max = n + n-1 + n-2 ;
	for ( ll i=0 ; i<n ; i++ )
		{
		cin >> a[i] ;
		}
	return 0 ;
}