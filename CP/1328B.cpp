#include<bits/stdc++.h>
#define ll long int
using namespace std ;

int main()
{
	int t ;
	cin >> t ;
		while(t--)
		{
			int n ;
			ll k ;
			cin >> n >> k ;
			char x[n+1] ;
			for ( int i=0 ; i<n ; i++ )	x[i] = 'a' ;
			 int first ;
			 if ( n<2 )	cout << "0\n" ;
			 bool f=0 ;
			 for (first=2 ; i<=n ; i++ )
			 {
			 	if ((first*(first-1))/2>k)	break ;	
			 	if ((first*(first-1))/2==k) { f=1 ; break ;}
			 }
			 if(f)
			 {
			 		x[n+1-first] = 'b' ;
			 		cout << x << "\n" ; 
			 }
			 if(!f)
			 {
			 	x[n+1-first+1] = 'b' ;
			 	k -= ((first-1)*(first-2))/2 ;
			 		x[n+1-k] = 'a' ;
			 }
		}

	return 0 ;
}