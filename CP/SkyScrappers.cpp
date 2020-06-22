#include<bits/stdc++.h>
#define ll long int
using namespace std ;

vector<unordered_map<ll,ll>> dp[2] ;

ll max ( ll a , ll b )
{
	return (a>b)? a:b ;
}

ll LDS ( int i , int n , vector<ll> a , ll prev=1000000001 )
{
	if ( i==n )	return 0 ;
	if ( dp[1][i].find(prev) == dp[1][i].end() )
	{
		ll var = 0 ;
		if ( prev >= a[i] )
		{
			var = 1 + LDS ( i+1 , n , a , a[i] ) ;
		}
		if ( prev < a[i] )
		{
			var = LDS ( i+1 , n , a , a[i] );
		}
		dp[1][i][prev] = var ;
	} 
return dp[1][i][prev] ;
}

ll LIS ( int i , int n , vector<ll> a , ll prev=-1 )
{
		if ( i==n )	return 0 ;
		if ( dp[0][i].find(prev)==dp[0][i].end())
		{
			ll var=0 , var1 = 0 ;
			if ( prev < a[i] )
			{
				var = 1 + LIS ( i+1 , n , a , a[i] ) ;
			}
			if ( prev > a[i] )
			{
				var = LIS ( i+1 , n , a , prev ) ;
			}
			if ( prev == a[i] )
			{
				var = 1 + LIS ( i+1 , n , a , prev ) ;
			}
			var1 = 1 + LDS ( i+1 , n , a , a[i] ) ;
			dp[0][i].insert(pair<ll,ll>(prev,var)) ;
			dp[1][i].insert(pair<ll,ll>(prev,var1)) ;
		}	
return max ( dp[0][i][prev] , dp[1][i][prev] ) ;
}

int main()
{
	int n ;
	cin >> n ;
		vector<ll> a ;
		a = vector<ll> (n) ;

		dp[0] = vector<unordered_map<ll,ll>> (n) ;
		dp[1] = vector<unordered_map<ll,ll>> (n) ;
		
		for ( int i=0 ; i<n ; i++ )
		{
			cin >> a[i] ;
		}
		cout << max ( LIS (a,0,n) , LDS (a,0,n) ) ;
	return 0 ;
}