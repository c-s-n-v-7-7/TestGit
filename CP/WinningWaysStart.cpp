#include<iostream>
#include<unordered_map>
#include<utility>
using namespace std ;

int main()
{
	int t ;
	cin >> t ;
		while(t--)
		{
			int n , q ;
			long int a[n] ;
			cin >> n ;
			unordered_map<long int, int> freq[n];
			unordered_map<long int, int> :: iterator j ;
			for ( int i=0 ; i<n ; i++ )
			{
				cin >> a[i] ;
				if(i==0)	continue ;
				freq[i] = freq[i-1] ;
				j = freq[i].find(a[i]) ;
				if(j==freq[i].end())	freq[i].insert(pair<long int ,int>(a[i],1)) ;
				else	j->second++ ;
			}

			cin >> q ;
			while(q--)
			{
				int l , r ;
				cin >> l >> r ;
					unordered_map<long int,int> ToBeTaken ;
					ToBeTaken = freq[r-1] ;
				if(l!=1)
				{
					for ( auto it = freq[r-1].begin() ; it!=freq[r-1].end() ; ++it )
					{
						ToBeTaken[it->first] -= freq[l-2][it->first] ;
					}
				}
				
			}
		}
	return 0 ;
}