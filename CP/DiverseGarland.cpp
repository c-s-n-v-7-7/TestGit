//1108D 
//Need to print the string as well.
#include<bits/stdc++.h>
#define max 200002
using namespace std ;

int min ( int a , int b )
{
	return (a<b)? a:b ;
}

vector<int> dp[3] ;

int m ;

int minchange( char c[] , int i , int f )
{
		
	int cur = f ;

	if ( dp[cur][i] == -1 )
	{
		int next = 0 ;
	
		if ( c[i+1] == 'b' )	next = 1 ;
		if ( c[i+1] == 'g' )	next = 2 ;
		
		if ( cur == next )
		{
			int var1 , var2 ;
			var1 = 1 + minchange ( c , i+1 , (cur+1)%3 ) ;
			var2 = 1 + minchange ( c , i+1 , (cur+2)%3 ) ;
			dp[cur][i] = min ( var1 , var2 ) ;
		}
		
		else
		
		{
			int var1 , var2 ;
			var1 = minchange ( c , i+1 , next ) ;
			var2 = 1 + minchange ( c , i+1 , 3-(cur+next) ) ;
			dp[cur][i] = min ( var1 , var2 ) ;
		}
	}
return dp[cur][i] ;
}

int main()
{
	int n ;
	cin >> n ;
	
	char c[n+1] ;
	cin >> c ;
	
	//cout << "String Entered\n" ;
	
	m = max ;
    
    //cout << "Max Assigned\n" ;
    
	for  ( int i=0 ; i<3 ; i++ )
	{
	    dp[i] = vector<int> (n,-1) ;
	  //  cout << "DP initialised partially\n" ;
 	}
	
    
    dp[0][n-1] = 0 ;
	//cout << "Fully initialised red \n" ; 
	dp[1][n-1] = 0 ;
	//cout << "Fully initialised blue \n" ; 
	dp[2][n-1] = 0 ;
	//cout << "Fully initialised green \n" ; 

	/*for ( int i=0 ; i<3 ; i++ )
	{
	    for ( int j=0 ; j<n ; j++ )
	    {
	        cout << dp[i][j] << " " ;
	    }
	   cout << "\n" ;
	}*/
	
	int j = 0 ;
	
	if ( c[0] == 'b')	j=1 ;
	if ( c[0] == 'g' )	j=2 ;

	int v[3]  ;

	for ( int i=0 ; i<3 ; i++ )
	{
		v[i] = 1 + minchange( c , 0 , i ) ;
		if ( i==j )	v[i]-- ;
		m = min ( m , v[i] ) ;
	}	
	
	cout << m ;

	return 0 ;
	
}