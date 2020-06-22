#include<iostream>
#include<set>
using namespace std;

set<int> G[101] ;
int visited[101] ;

void dfs( int s )
{
    visited[s] = 1 ;
    for ( auto it=G[s].begin() ; it!=G[s].end() ; ++it)
    {
        if (!visited[*it])dfs(*it) ;
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
        if ( x < 0 ||  y < 0 )  break ;
        G[x].insert(y) ;
    }
    int cc=0 ;
    for ( int i=0 ; i<n ; i++ )
    {
        if (!visited[i])
        {
            cc++ ;
            dfs(i) ;
        }
    }
    cout << cc << "\n" ;
    return 0 ;
}