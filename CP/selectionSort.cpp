// This always sorts with time complexity of O(n^2) 
// Same as Bubble Sort except that we compare the next element with all the available choices 
#include<bits/stdc++.h>
#define MAX 100000 
using namespace std ;

int main()
{
	
	int n ;
	cin >> n ;

		vector<int> v ;
		v = vector<int>(n) ;	

	//	int k = MAX ;

	/*	
	*/
		
		for ( int i=0 ; i<n ; i++ )
		{
			int min = i ;
				for ( int j=i+1 ; i<n ; i++ )
				{
					if (v[j]<v[min])	
					{
						min = j;
					}
				}
			int t = v[min] ;
			v[min] = v[i] ;
			v[i] = t ;
		}
	for ( int i : v )
	{
		cout << i << " " ;
	}
return 0 ;
}