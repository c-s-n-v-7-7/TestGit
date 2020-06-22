#include<iostream>
using namespace std ;

int min ( int a , int b )
{
    return (a<b)? a : b ;
}
//Works for negative edge weights as well 
int main()
{
    int n ;
    cin >> n ;
    int x , y ;
    while(1)
    {
        cin >> x >> y >> w ;
        if ( x < 0 || y < 0 )   break ;
        else
        {
            G[x].insert(pair<int,int>(y,w)) ;
            G[y].insert(pair<int,int>(x,w)) ;
        }
    }
    int distance[n+1] ;
    distance[0] = 0 ;
    distance[1] = 0 ;
    for ( int i=2 ; i<=n ; i++ )    distance[i] = 9999 ;
    for ( int i=1 ; i<n ; i++ )
    {
        for ( auto it=G[i].begin() ; it!=G[i].end() ; ++it)
        {
            distance[it->first] = min ( distance[it->first] , distance[i] + it->second ) ;
        }
    }
    for ( int i=1 ; i<=n ; i++ )
    {
        cout << i << " " << distance[i] << "\n" ;
    }
    return 0 ;
}