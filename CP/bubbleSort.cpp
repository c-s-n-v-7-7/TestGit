#include<bits/stdc++.h>
using namespace std ;

int main()
{
	int n ;
	cin >> n ;
		
		vector<int> v ;
		v = vector<int> (n) ;
		
		for ( int i=0 ; i<n ; i++ )
			cin >> v[i] ;

		for ( int i=0 ; i<n-1 ; i++ )
		{
			for ( int j=i+1 ; j<n ; j++ )
			{
				if (v[i]>v[j])
				{
					int t = v[i] ;
					v[i] = v[j] ;//Basic Swap and compare 
					v[j] = t ;
				}
			}
		}

		for ( int i=0 ; i<n ; i++ )
			cout << v[i] << " " ;

	return 0 ;
}