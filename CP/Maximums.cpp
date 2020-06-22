#include<bits/stdc++.h>
#define ll long long int
using namespace std ;

int main()
{
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
	ll n ;
	cin >> n ;
	ll a[n] ;
	ll dp[n+1] ;
	dp[0] = 0 ;
	for ( ll i=0 ; i<n ; i++ )
	{
		cin >> a[i] ;
		dp[i+1] = dp[i] + a[i] ; 
	}
	for ( ll i=1 ; i<=n ; i++ )
		cout << dp[i] << " " ;
	return 0 ;
}