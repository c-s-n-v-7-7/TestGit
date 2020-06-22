#include<bits/stdc++.h>
using namespace std ;

set<set<int>> coins ;

void Sum ( int s , int a[] , int n , set<int> w )
{
	if ( s == 0 )	coins.insert(w) ;
	if ( s<0 )	return ;
	
	for ( int i=0 ; i<n ; i++ )
	{
		set<int> g =  w  ;
		if ( s - a[i] < 0 )	break ;
		if ( s-a[i] >= 0 )	g.insert(a[i]) ;
		Sum ( s-a[i] , a , n , g ) ;
	}

return ;
}

int main()
{
	int s ; 
	cin >> s ;
	 int n ;
	 cin >> n ;
	 int a[n] ;
	 for ( int i=0 ; i<n ; i++ )
	 		cin >> a[i] ;
	 sort(a.begin(),a.end()) ;
	 set<int> w ;
	 w.clear() ;
	 Sum( s , a , n , w )  ;
	 for ( set<int> a : coins )
	 {
	 	for ( int r : a )	
	 		cout << r << " " ;
	 	cout << "\n" ; 
	 }
	return 0 ;
}