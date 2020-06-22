#include<iostream>
#include<utility>
#include<map>

using namespace std ;

multimap<int,int> Path ;
int visited[1000001] ;
int a[1000001] ;

int max ( int a , int b )
{
    return (a>b)? a:b ;
}

int dfs ( multimap<int,int>::iterator it  , int val , int step )
{
    visited[it->first] = 1 ;
    val += a[x] ;
    multimap<int,int>::iterator k , j ;
    it = Path.find(x) ;
    int c1=0 , c=0 ;
    for ( j = it ; j->first !=it->first ; ++j )
    {
            c += max(dfs (j->second), val , step+1 );
    }
    return val/n + val ;
}

int main()
{
    int t ;
    cin >> t ;
    while(t--)
    {
        int n ;
        cin >>n ;
        int a[n+1] ;
        for ( int i=1 ; i<=n ; i++ )
        cin >> a[i] ;
        int x , y ;
        for( int i=0 ; i<n-1 ; i++ )
        {
            cin >> x >> y ;
            Path.insert(pair<int,int>(x,y)) ;
        }
        int weight = 0 ;
        int var ;
        for ( int i=1 ; i<=n ; i++ )
        visited[i] = 0 ;
        for ( auto it = Path.begin() ; it!=Path.end() ; ++it )
        {
            if (!visited[*it])
                {
                    var += a[*it] ;
                    weight = max (dfs( it , 0 , 0 ),weight) ;
                }
        } 
    cout << weight << "\n" ;
    for ( int i=0 ; i<=n ; i++ )
    visited[i] = 0 ;
    a[i] = 0; 
    Path.clear() ;
    }
    return 0 ;
}