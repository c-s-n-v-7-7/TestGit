#include<bits/stdc++.h>
using namespace std ;

int main()
{
	int t ;
	cin >> t ;
	while(t--)
	{
		int n ;
		cin >> n ;
			int t[n] ;
			int c[n] ;
		
			for (int i=0 ; i<n ; i++ )
			{
				cin >> t[i] ;
				c[i] = 1 ;
			}

		for ( int i=0 ; i<n ; i++ )
		{
				if (a[i]!=a[i-1])	
				{
					if ( c[i-1] == 1 )	c[i] = 2 ;
					else	c[i] = 1 ;
				}	
		}
		if ( c[0] == c[n-1] )	c[n-1] = 3 ;
		for ( int i=0 ; i<n ; i++ )	cout << c[i] << " " ;
			cout << "\n" ;
	}
	return 0 ;
}