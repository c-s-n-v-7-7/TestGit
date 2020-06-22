#include<bits/stdc++.h>
using namespace std ;

int max ( int a , int b )
{
	return (a>b)? a:b ;
}

int min ( int a , int b )
{
	return (a>b)? a:b ;
}

int main()
{
	int n , a , b ;
	int m = 0 ;
	for ( int i=1 ; i<n ; i++ )
	{
			m = max ( min ( a/i , b/(n-i) ) , m ) ;
	}
	cout << m ;
	return 0 ;
}