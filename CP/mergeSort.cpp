#include<bits/stdc++.h>
using namespace std ;

vector<int> v ;



void ms ( int l , int h )
{
	int mid = (l+h)/2 ;
	ms (l,m) ;
	ms (m+1,h) ;
		
}

int main()
{
	int n ;
	cin >> n ;

	v = vector<int> (n) ;

	for (int i=0 ; i<n ; i++ )
	{
		cin >> v[i] ;
	}
		ms(0,n) ;
	return 0 ;
}