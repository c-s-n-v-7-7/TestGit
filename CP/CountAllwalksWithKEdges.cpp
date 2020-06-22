#include<iostream>
#include<set>
using namespace std ;

int visited[101] ;
set<int> G[101] ;
int ways[101][101] ;

int Possiblities ( int src , int des , int k )
{
    if ( src == des && k == 0 ) return 1 ;
    else    if ((k==0 && src!=des)&&(k!=0&&src==des)) return 0 ;
    else
    {   
        if ( ways[src][k] == -1 )
        {
        int var = 0 ;
        for ( auto it = G[src].begin() ; it!=G[src].end() ; ++it )
            {
                if ( !visited[*it] )   
                    {
                visited[*it] = 1 ;
                var +=  Possiblities( *it , des , k-1 ) ; 
                visited[*it] = 0 ;
                    }
            ways[src][k] = var ;
            }
        }
    return ways[src][k] ;
    }   
}

int main()
{
    int n ;
    cin >> n ;
    int x , y ;
    while(1)
    {
        cin >> x >> y ;
        if ( x < 0 || y < 0 )   break ;
        G[x].insert(y) ;
        G[y].insert(x) ;
    }
    int k ; 
    int src , des ;
    cin >> src >> des ;
    cin >> k ;
    for ( int i=0 ; i<=n ; i++ )
    {
        visited[i] = 0 ;
    }
    for ( int i=0 ; i<=n ; i++ )
    {
        for ( int j=0 ; j<=n ; j++ )
        {
            ways[i][j] = -1 ;       
        }
    }    
        visited[src] = 1 ;
    cout<<Possiblities( src , des , k ) ;
    
    return 0 ;
}