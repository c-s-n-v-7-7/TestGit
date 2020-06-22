#include<bits/stdc++.h>
#define p 1000000007
#define ll long long int 
using namespace std ;

vector<vector<ll>> dp ;
long int m , n ;
ll Count( int r , int c )
{
	if(r>m||c>n||r<0||c<0)	return 0 ;
	if(dp[r][c] == -1)
	{
		dp[r][c] = 
	}
}

int main()
{
	cin >> m >> n ;
		dp = vector<vector<int>> (m) ;
		for ( long int i=0 ; i<m ; i++ )
		{
			dp[i] = vector<ll> (n,-1) ;
		}
		for ( int i=0 ; i<n ; i++ )
			dp[m-1][i]=1 ;
		for ( int i=1 ; i<m ; i+=2 )
		{
			count +=	Count(0,1) ; 
		}
	return 0 ;
}