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
		if(n==1)	cout << "-1\n" ;

	int a[n] ;
	
			for ( int j=9 ; j>=2 ; j-- )
			{
				for ( int i=n-(10-j) ; i>=0 ; i-=8 )
					{
						a[i] = j ;
					}
			}
	for ( int i=0 ; i<n ; i++ )	cout << a[i] ;
		cout << "\n" ;
		} 
	return 0 ;
}