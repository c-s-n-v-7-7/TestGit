#include<iostream>
#include<unordered_set>
using namespace std ;

int dp[101] ;
int pre[101] ;
unordered_set<int> g[101] ;

int max ( int a,  int b )
{
	return (a>b)? a:b ;
}

int Height( int src )
{
	int h=0 ;
		if ( dp[src] == -1 )
		{
	for ( int child : g[src] )
		{
			if ( pre[src] !=child )	
				{
					pre[child] = src ;
					h = max ( h , 1+Height(child) ) ;
				}
		}
			dp[src] = h ;
		}
	else	return dp[src] ;
}

int main()
{
		int n ;
		cin >> n ;
			int x , y ;
			dp[n] = -1 ;
			pre[n] = -1 ;
			for ( int i=0 ; i<n-1 ; i++ )
				{
					cin >> x >> y ;
					g[x].insert(y) ;
					g[y].insert(x) ;
					dp[i] = -1 ;
					pre[i] = -1 ;
				}

		cin >> x ;
		cout<<Height(x) ;
		    
			//cout << Height(x) ;

	return 0 ;
}