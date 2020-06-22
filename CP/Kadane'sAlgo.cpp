#include<bits/stdc++.h>
using namespace std ;

int max ( int a , int b )
{
	return (a>b)? a:b ;
}

int main()
{
	int n ;
	cin >> n ;
	
	int x[n] ;
		
		for ( int i=0 ; i<n ; i++ )
			cin >> x[i] ;
		
		int s = 0 ;
		s = max ( s , a[0] ) ;
		for ( int i=1 ; i<n ; i++ )
		{
			s = max ( s+a[i] , a[i] ) ;
		}
		cout << s ;
	return 0 ;
}