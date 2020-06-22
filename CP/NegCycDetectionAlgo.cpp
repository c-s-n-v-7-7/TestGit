#include<iostream>
#include<map>
#include<utility>
using namespace std ;

int min ( int a , int b )
{
	return (a<b) ? a:b ;
}
bool vis[101] ;
int weight[101] ;
int lv[101] ;
int ts[101] ;
map<int,int> g[101] ;
bool NegCyc( int src , int wt=0 , int par=0 , int t=0 )
{
	ts[src] = t ;
	weight[src] = wt ;
	lv[src] = min ( lv[par] , t ) ;
		for ( auto j = g[src].begin() ; j!=g[src].end() ; ++j )
		{
			if(!vis[j->first])	
			{
				vis[j->first] = 1 ;
				if (NegCyc(j->first,wt+j->second,src,t+1)) return true; 
			}
			else
			{
				if (lv[src]>=ts[j->first])
				{
					return (weight[j->first] > weight[src] + j->second)?  true:false ;	
			    					weight[j->first] = weight[src]+j->second ;	
				}
			}
		}
}

int main()
{
	int n , m ;
	cin >> n >> m ;
		int x ,  y , w ;
		for ( int i=0 ; i<=n ; i++ )
		{ vis[i] = 0 ;	lv[i] = 0 ; ts[i] = 0 ; }
		for ( int i=0 ; i<m ; i++ )
		{
			cin >> x >> y >> w ; 
				g[x].insert(pair<int,int>(y,w)) ;
				g[y].insert(pair<int,int>(x,w)) ;
		}
		    vis[1] = 1 ;
			if(NegCyc(1))	cout << "Negative cycle is present\n" ;
			else	cout << "No negative cycle is present\n" ;
   // for ( int i=1 ; i<=n ; i++ )
    //{
     //       cout << "LV : " << lv[i] << " TS : " << ts[i] << " W : " << weight[i] << "\n" ;
    //}

	return 0 ;
}