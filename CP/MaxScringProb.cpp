#include<iostream>
using namespace std ;

int max ( int a , int b , int c=0 )
{
	if ( a>=b && a>=c )	return a ;
	if ( b>=a && b>=c )	return b ;
	if ( c>=a && c>=b )	return c ;
}

long int decode ( char x , long int total , int val )
{
	long int cop = total ;
		if ( x == '.' )	return total ;
		if ( x == 'd' )	return total+2*val ;
		if ( x == 't' )	return total+3*val ;
		if ( x == 'D' )	return total*2 ;
		if ( x == 'T' )	return total*3 ;
}

long int dp[9][100] ;
int n ;
long int value ( char x[] , int ind=0 , int taken=0 , long int total=0 )
{
		if ( ind == n )	return total ;
	if ( dp[taken][ind] !=-1 )
	{
	int var = 0 ;
	int val ;
	
	if ( x[taken] == '\0' )	val = 0 ;
	else	val = points[x[taken]] ;	

	int var1 = value( x , taken+1 , ind+1 , decode( x[i],total,val) ) ;
	
	int var2 = value( x , taken , int+1 , total) ;
	
		var = max ( var1 , var2 ) ;
		dp[taken][ind] = var ;
	}
return dp[taken][ind] ;
}

int main()
{
		int t ;
		cin >> t ;
			while(t--)
			{
				cin >> n ;
					char x[n+1] ;
				cin >> x ;
				for ( int i=0 ; i<n ; i++ )
				{
					for ( int j=0 ; j<=8 ; j++ )
							dp[j][i]=-1 ;
				}
		int points[8] ;
   enum = { 'I','I','T','M','A','N','D','I' } ;
	
				for ( enum i=0 ; i<8 ; i++ )
				{
					cin >> points[i] ;
				}
				points[0] = points[1] = points[7] = 
				max ( points[0] , points[1] , points[7]) ;
		cout << value(x) ;
			}
	return 0 ;
}