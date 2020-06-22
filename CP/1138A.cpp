#include<bits/stdc++.h>
using namespace std ;

int max ( int a , int b )
{
	return (a>b)? a:b ;
}

int min( int a , int b )
{
    return (a>b) ? b:a ;
}

int main()
{
	long int n ;
	cin >> n ;
		int a[n] ;
	for  ( int i=0 ; i<n; i++ )
	{
			cin >> a[i] ;
	}
	/*int mv = 0  ;
	for ( int i=0 ; i<n-1 ; i++ )
	{
			int k=i , l=i+1 ;
			int count = 0 ;
			while(a[k--]!=a[l++]&&k>=0&&l<n)
			{
				count+=2 ;
			}
			mv = max ( mv , count ) ;
	}*/
	vector<int> window ;
	int l=1 ;
	for ( int i=0 ; i<n-1 ; i++ )
	{
	    if ( a[i] != a[i+1] )    { window.push_back(l) ; l=1 ; continue ;}
	    l++ ;
	   // cout << i << " " << l << "\n" ;
	}
	window.push_back(l) ;
	//for ( int i : window )
	//cout << i << " " ;
	int p = 0 , mv = 0 ;
	for ( int i=0 ; i<window.size()-1 ; i++ )
	{
	    mv = max ( mv , 2*min(window[i],window[i+1]) ) ;
	}
	cout << mv ;
	return 0 ;
}