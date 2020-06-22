#include<bits/stdc++.h>
using namespace std ;

vector<vector<int>> dp ;

int max ( int a , int b )
{
	return (a>b)? a:b ;
}

int main()
{
	string s ;
	cin >> s ;
		dp = vector<vector<int>> (s.size(),-1) ;
		
		for ( int i=0 ; i<s.size() ; i++ )
		{
			dp[i] = vector<int> (s.size(),-1) ;
		}

		for ( int i=0 ; i<s.size() ; i++ )
			dp[i][i] = 1 ;

		for ( int k=1 ; k<n-1 ; k++ )
		{
			for ( int i=0 ; i+k<n ; i++ )
			{
				if(s[i]==s[i+k] && k==1 )	dp[i][i+k]=2 ;
				else	if(s[i]==s[i+k]) dp[i][j] = dp[i+1][j-1]+2 ;
				else	dp[i][j] = max ( dp[i][j-1] , dp[i+1][j] ) ;  
			}
		}
		cout << dp[0][n-1] ;
	return 0 ;
}