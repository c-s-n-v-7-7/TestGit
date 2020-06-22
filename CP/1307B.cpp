#include<bits/stdc++.h>
#include<algorithm>
#define int_max 10000000001
#define ll long long int
using namespace std ;

ll min ( ll a , ll b )
{
	return (a<b)? a:b ;
}

int main()
{
ios_base::sync_with_stdio(false);
    cin.tie(NULL);
	int t ;
	cin >> t ;
		while(t--)
		{
			int n ;
			long int x ;
			cin >> n >> x ;
				int a[n] ;
				for ( int i=0 ; i<n ; i++ )
					cin >> a[i] ;
				sort(a,a+n) ;
				ll minval =int_max ;
				ll dp[x+1] = {int_max} ;
				dp[0] = 0 ;
				
				for ( int i=0 ; i<x ; i++ )
				{
					if(dp[i]!=int_max) 
						{
							for ( int j=0 ; j<n ; j++ )
							{
								if ( i+a[j] > x )	break ;
								dp[i+a[j]] = min ( dp[i+a[j]] , dp[i]+1 ) ; 
							}
						}
				}
				cout << min ( dp[x] , 2*((x/a[n-1])+1) ) ;
		}
	return 0 ; 
}