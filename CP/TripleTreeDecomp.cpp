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
				unordered_set<int> m[n+1] ;
				int x , y ;
			for ( int i=0 ; i<n-1 ; i++ )
			{
				cin >> x >> y ;
				m[x].insert(y) ;
				m[y].insert(x) ;
			}
			
			for (int i=0 ; i<=n ; i++ )
			{
				if(m[i].size()>=3)	cout << i << "\n" ;
			}
			
		}
	return 0 ;
}