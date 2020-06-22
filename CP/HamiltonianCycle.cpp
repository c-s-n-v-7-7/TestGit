#include<iostream>
using namespace std ;

int visited[1001] ;

int HamiltonianCycle( int src , int n )
{
    //if ( visited[src] == 1 )    return false ;
    if ( src == n ) return 1 ;
        visited[src] = 1 ;
        int var = 0 ;
        for ( auto it = G[src].begin() ; it!=G[src].end() ; ++it )
        {
                if(!visited[*it])   
                {
                    var += ( HamiltonianCycle( *it , n ) ) ;
                }
        }
    return var ; 
    
}

int main()
{
    int n ;
    cin >> n ;
    int x , y , w ;
    while(1)
    {
        cin>>x>>y ;
        if ( x < 0 || y < 0 )   break ;
        else
        {
            G[x].push_back(y) ;
            G[y].push_back(x) ;
        }
        
    }
    for  ( int i=0 ; i<=n ; i++ )
    {
        visited[i] = -1 ;
    }
    visited[1] = 1 ;
    HamiltonianCycle( 1 , n ) ;
    return 0 ;
}