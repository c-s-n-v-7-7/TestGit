#include<bits/stdc++.h>
using namespace std ;

int main()
{
	int n ;
	cin >> n ;

	vector<int> v ; 
	v = vector<int> (n) ;

	for ( int i=0 ; i<n ; i++ )
	{
		cin >> v[i] ;
	}

	for ( int i=1 ; i<n ; i++ )
	{
		int k = v[i] ; 		// 	Assigning the key value which will help us shift the cards
		int j = i ;			//	Taking the next card in the unsorted hand
			while(v[j-1]>k&&j>=1)
			{	
				v[j] = v[j-1] ;		// Shifting the cards on the sorted hand 
				j-- ;
			}
		v[j] = k ;		// Placing the next card in the sorted hand 
	}

	for ( int i=0 ; i<n ; i++ )
	{
		cout << v[i] << " " ;
	}
	return 0 ;
}