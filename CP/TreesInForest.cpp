#include<iostream>
#include<set>
using namespace std;

int visited[101] ;

int NoOfTrees( int src , int n , set<int>G[] )
{
    int np=1 ;
    for( auto it = G[src].begin() ; it!=G[src].end() ; ++it )
    {
        if ( visited[*it]==-1)
        {
            visited[*it] = 1 ;
            NoOfTrees( *it , n , G ) ;
        }
    }
    for ( int i=0 ; i<=n ; i++ )
    {
        if(visited[i]==-1)  np+= NoOfTrees(i,n,G) ;  
    }
return np ;
}
int main()
{
    int n ;
    cin >> n ;
    set<int> G[n+1] ;
    int x , y ; 
        for( int i=0 ; i<n-1 ; i++ )
        {
            cin >>x >> y ;
            G[x].insert(y) ;
            G[y].insert(-x) ;
        }
        for ( int i=0 ; i<= n ; i++ )
        {
            visited[i] = -1 ;
        }
        cout << NoOfTrees( 1 , n , G ) ;
    return 0 ;
}