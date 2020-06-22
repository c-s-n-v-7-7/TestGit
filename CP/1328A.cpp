#include<bits/stdc++.h>
using namespace std ;

int main()
{
	int t ;
	cin >> t ;
	while(t--)
	{
	long int a , b ;
	cin >> a >> b ;

	if ( a>b||b%a==0)	{ cout << "0\n" ; continue ; }
	if (a*a >=b)	{cout << b-a << "\n" ; continue ; }	
	
	for ( int i=2 ; i*i<n ; i++ )
	{
		if ((b/i - a)<=0)	break ;
	}
		cout << b/(i-1)-a << "\n" ;

	}
	return 0 ;
}