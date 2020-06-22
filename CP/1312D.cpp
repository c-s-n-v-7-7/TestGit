#include<bits/stdc++.h>
#define ll long long int
using namespace std ;

ll choose[200001][200001] ;

ll C( int n , int r )
{
	if(choose[n][r]==-1)	
	{
		choose[n][r] = choose[n-1][r-1] + choose[n-1][r] ;
	}
	return choose[n][r] ;
}

int main()
{
	int n , m ;
	cin >> n >> m ;
	if(n>m+1)	cout << "0\n" ;
	else
	{
	for ( int i=0 ; i<m ; i++ )
	{
		for(int j=0 ; j<=i ; j++ )	choose[i][j] = -1 ;  
		for (j=i+1 ; j<n+1 ; j++ )	choose[i][j] = 0 ;
	}
	for ( int i=0 ; i<m+1 ; i++ )	choose[i][i]=1 ;
	for ( int i=1 ; i<m+1 ; i++ )
	{
		choose[i][1] = i ;
	}
		cout << C(m,n-1) ;
	}
	return 0 ;
}