#include<bits/stdc++.h>
using namespace std ;

vector<int> a ;

int max ( int a , int b ) {
	return (a>b)? a:b ;
}

int Search ( int s , int f ) {
	if (s>f)	return s ;
	if 	(s==f)	return s ;
	if (s<f)
	{
		int m = s + (f-s)/2 ;
			if (a[m]<a[m-1]&&a[m]>a[m+1])	return m ;
			if (a[m]<a[m-1]&&a[m]<a[m+1])	
			{
				s = m+1 ;
			}
			if (a[m]>a[m-1]&&a[m]>a[m+1])
			{
				f = m-1 ;
			}	
		return Search(s,f) ;
	}
}

int main()
{
	int n ;
	cin >> n ;

		a = vector<int> (n) ;

		for ( int i=0 ;i<n ; i++ )
			cin >> a[i] ;

		int pos = Search(0,n) ;

		cout << pos ;

	return 0 ;
}