#include<iostream>
#include<unordered_set>
#include<queue>
using namespace std ;

int main()
{
		int n , m , k  ;
		cin >> n >> m >> k ;
			int a[k] ;

				for ( int i=0 ; i<k ; i++ )
					cin >> a[i] ;
			
			unordered_set<int> s[n+1] ;
				
				for ( int i=0 ; i<m ; i++ )
					{
						int x , y ;
							cin >> x >> y ;
						s[x].insert(y) ;
						s[y].insert(x) ;
					}

				s[1].insert(0) ;
			
			queue<int> start ;
					
					start.push(1) ;
				int prev[n+1] ;
				
				for ( int i=0 ; i<=n ; i++ )	prev[i] = -1 ;
				prev[0] = 0 ;
				prev[1] = 0 ;
				
				while(!start.empty())
				{
				for ( auto it = s[start.front()].begin() ; it!=s[start.front()].end() ; ++it )
					{
						if ( prev[*it] == -1 )	
						{
							prev[*it] = start.front ;
							if (*it==n) break ;
								start.push(*it) ;
						}

					}
					start.pop() ;
				}
				
				j = n ;
					int steps = 0 ;
					
					while ( j!=1 )
					{	
						j = prev[j] ;
							i++ ;
					}
				
				cout << i ;
	
	return 0 ;
}