#include<bits/stdc++.h>
#define ll long int
using namespace std ;

ll a[1001] ;
ll dp[1001][1001] ;
bool vis[1001] ;
int k , n ;


long int Count ( int i , int j )
{
	vis[i] = 1 ;
	if ( dp[i][j] == -1 )
	{
		long int var = 0 ;
		for ( int l=0 ; l<n ; l++ )
		{
			if(!vis[l]&&a[i]>=a[l])
			{
				var += Count(l,j-1) ;
			}	
		}
		dp[i][j] = var ;
	}
	vis[i] = 0 ;
return dp[i][j] ;
}
int main()
{

	cin >> n >> k ;

	
	for ( int i=0 ; i<n ; i++ )	
	cin >> a[i] ;

	sort(a,a+n) ;
        //for ( int i=0 ; i<n ; i++ ) cout << a[i] << " " ;
	for ( int i=0 ; i<=n ; i++ )
	{
		vis[i] = 0 ;
		for ( int j=1 ; j<=n ; j++ )
			dp[i][j] = -1 ;
		dp[i][0] = 1 ;
	}

	long int W=0 ;
	for ( int i=0 ; i<n ; i++ )
	{
		W += Count(i,k) ;
	}
	
	for ( int i=0 ; i<=n ; i++ )
	{
	    for ( int j=1 ; j<=k ; j++ )
	    {
	        cout << dp[i][j] << " " ;
	    }
	    cout << "\n" ;
	}
	cout << W << "\n" ;
	return 0 ;
}