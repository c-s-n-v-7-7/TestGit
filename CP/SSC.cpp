#include<iostream>
#include<set>
using namespace std ;
set<int> g[101] ;
int vis[101];
int ts[101] ;
int lowval[101];

int cyclen ;

int max ( int a , int b )
{
    return (a>b)? a:b ;
}

void lookup( int src , int t=1 , int lv = 1 )
{
    ts[src] = t ;
    lowval[src] = lv ;
    vis[src] = 1 ;
    for ( auto it=g[src].begin() ; it!=g[src].end() ; ++it )
    {
        if(!vis[*it]) { lookup(*it,t+1,lv) ;  } 
        
        else
        {
            if ( lowval[src]>=ts[*it] ) cyclen =  max(cyclen,1+ts[src] - ts[*it]) ;  
        }
    }
}

int main()
{
        int n , m ;
        cin >> n >> m ;
        for ( int i=0 ; i<=n ; i++ )    vis[i] = 0 ;
        cyclen = 0 ;
        int x , y ;
        for ( int i=0 ; i<m ; i++ )
        {
            cin >> x >> y ;
            g[x].insert(y) ;
            g[y].insert(x) ;
        }
        lookup(1) ;
        cout << cyclen ;
    return 0 ;
}