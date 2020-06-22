#include<bits/stdc++.h>
using namespace std ;

int main()
{
	int t , s ;
	cin >> t >> s ;
	long int n ;
	long int a[n] , b[n] ;
	cin >> n ;
	for ( long int i=0 ; i<n ; i++ )
	{
		cin >> a[i] ;
	}
	for ( long int i=0 ; i<n ; i++ )
	{
	cin >> b[i] ;
	}
		sort(a,a+n) ;
		sort(b,b+n) ;
	if(s==1)
	{
	bool f=0 ;
		for ( long int i=0 ; i<n ; i++ )
		{
			if(a[i]>=b[i])	{f=1;btreak;}
		}
		if(f)	cout << "NO\n" ;
		else	cout << "YES\n" ;
	}
	
	return 0 ;
}