#include<bits/stdc++.h>
using namespace std ;

int C ( int n , int r , vector<vector<int>>&c )
{
	if(c[n][r]==-1)	
	{
		c[n][r] = (C(n-1,r-1,c)+C(n-1,r,c)) ;
	} 
return c[n][r] ;
}

int main()
{
	int n , r ;
	//cin >> n >> e ;

	//int a , b ;
	//	cin >> a >> b ;

	vector<vector<int>> c ;
	c = vector<vector<int>> (n) ;
	
	for ( int i=0 ; i<n ; i++ )
	{
		c[i] = vector<int> (n,-1) ;
	}
	
	for ( int i=0 ; i<n ; i++ )
	{
		for ( int j=i+1 ; j<n ; j++ )
		{
			c[i][j] = 0 ;
		}
		c[i][0] = 1 ;
		c[i][1] = i ;
	}

	cout << C(n,r,c) ;

	return 0 ;
}