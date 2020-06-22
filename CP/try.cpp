#include<bits/stdc++.h>
#include<algorithm>
using namespace std ;

long int max ( long int a , long int b )
{
	return (a>b)? a:b ;
}
int main()
{
	int t ;
	cin >>t ;
		while(t--)
		{
			int n ;
			long long int x ;
			cin >> n >> x ;
				long int a[n] ;
			for ( int i=0 ; i<n ; i++ )
					cin >> a[i] ;
			long int div=0 , mv = 0 ;
			for ( int i=0 ; i<n ; i++ )
			{
				if ( mv < a[i] ) mv = a[i] ;
			}
			long int h = x/mv ;
			if ( x%mv !=0 )	h++ ;
			cout << max(h,2) << "\n" ;
		}
	return 0 ;
}