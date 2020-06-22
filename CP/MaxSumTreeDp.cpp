#include<iostream>
#include<unordered_set>
using namespace std ;

int pre[101] ;
int dp[101] ;
unordered_set<int> g[101] ;

int max ( int a , int b )
{
	return (a>b)? a:b ;
}

int maxSum ( int s )
{
	int val = 0  ;
		for ( auto it=g[s].begin() ; it!=g[s].end() ; ++it )
		{
			if ( pre[*it] ==-1 )
			{
			dp[*it] = max ( dp[*it] , maxSum(*it)) ;
				pre[*it] = s ; 
			}
			val = max ( val , dp[*it] ) ;
		}
	dp[s] = s+val  ;
return dp[s] ;
}

int main()
{
		int n ;
		cin >> n ;	// No . of nodes 
		pre[0] = 0 ;

			for ( int i=1 ; i<n ; i++ )
				{
					int x,y ;
						cin >> x >> y ;		//	Adding edges 
					g[x].insert(y) ;
					g[y].insert(x) ;
					pre[i] = -1 ;
				}
			// Given a tree with N nodes and N-1 edges, calculate the maximum sum of the node values from root to any of the leaves without re-visiting any //node.

			cout << "Enter Source : " ;	int s ;
			cin >> s ;

			for ( int i=0 ; i<=n ; i++ )	dp[i] = -1 ;

			cout << maxSum( s ) ;

	return 0 ;
}