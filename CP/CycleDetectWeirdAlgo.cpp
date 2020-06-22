#include<iostream>
#include<set>
using namespace std ;

bool vis[101] ;
int ts[101] ;
int lv[101] ;

set<int> g[101] ;

int min ( int a , int b )
{
	return (a<b)? a:b ;
}

bool Cycle( int src , int par=0 , int t = 0 )
{
	ts[src] = t ;
	if ( par == 0 ) lv[src] = 0 ;
else	lv[src] = min ( lv[par] , ts[src] ) ;
	for ( int j : g[src] )
	{
		if ( j == par )	continue ;
		if ( !vis[j] ) 
		{
			vis[j] = 1 ;
				if ( Cycle( j , src , t+1 ) ) return true ;
		}
		else
		{
			if ( lv[src] >= ts[j] )	return true ;
		}
	}
return false ;
}

int main()
{
		
				int n , m ;
				cin >> n >> m ;
			for ( int i=0 ; i<=n ; i++ )	vis[i] = 0 ;
		for ( int i=0 ; i<=n ; i++ )	{ts[i]=-1;lv[i]=-1;}
				int x , y ;
					for ( int i=0 ; i<m ; i++ )
						{
							cin >> x >> y ;
							g[x].insert(y) ;
							g[y].insert(x) ;
						}
						vis[1]=1 ;
					
				if(Cycle(1))	cout << "Cycle's present\n" ;
				else	cout << "Cycle's absent\n" ;
			//for ( int i=1  ; i<5 ; i++ )
					//    cout << " lv : ts : " << lv[i] << " " << ts[i] ;
	return 0 ;
}