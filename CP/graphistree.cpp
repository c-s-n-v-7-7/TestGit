#include<iostream>
#include<set>
#include<utility>
using namespace std;

int visited[101] ;
set<int> Graph[101] ;

bool dfs ( int x , int y=0 )
{
    visited[x] = 1 ;
    for ( auto it = G[x].begin() ; it!=G[x].end() ; ++it )
    {
        if ( *it == x ) continue ;
        if ( visited[*it] ) return true ;
        if (dfs(*it,x)) return true ;
    }
return false ;}

int main()
{
    int n ;
    int x , y ;
    cin >> n ;
    for ( int i=0 ; i<n-1 ; i++ )
    {
            cin >> x >> y ;
            Graph[x].insert(y) ;
    }
    for ( int i=0 ; i<=n ; i++ ) 
    {
        visited[i] = 1 ;
    }
    if(dfs( 1 ))    cout << "Not a Tree" ;
    else    cout<<"Tree" ;
    return 0 ;
}